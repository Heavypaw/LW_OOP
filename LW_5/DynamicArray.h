#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory_resource>
#include <iterator>

template <typename T>
class DynamicArray {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit iterator(pointer ptr) : ptr_(ptr) {}

        reference operator*() const { return *ptr_; }
        pointer operator->() { return ptr_; }
        iterator& operator++() { ++ptr_; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++ptr_; return tmp; }
        friend bool operator==(const iterator& a, const iterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!=(const iterator& a, const iterator& b) { return a.ptr_ != b.ptr_; };

    private:
        pointer ptr_;
    };

    explicit DynamicArray(std::pmr::memory_resource* mr = std::pmr::get_default_resource())
        : allocator_(mr), data_(nullptr), size_(0), capacity_(0) {}

    ~DynamicArray() {
        for (size_type i = 0; i < size_; ++i) {
            allocator_.destroy(data_ + i);
        }
        allocator_.deallocate(data_, capacity_);
    }

    void push_back(const_reference value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        allocator_.construct(data_ + size_, value);
        ++size_;
    }

    void reserve(size_type new_capacity) {
        if (new_capacity > capacity_) {
            pointer new_data = allocator_.allocate(new_capacity);
            for (size_type i = 0; i < size_; ++i) {
                allocator_.construct(new_data + i, std::move(data_[i]));
                allocator_.destroy(data_ + i);
            }
            allocator_.deallocate(data_, capacity_);
            data_ = new_data;
            capacity_ = new_capacity;
        }
    }

    size_type size() const { return size_; }
    bool empty() const { return size_ == 0; }

    iterator begin() { return iterator(data_); }
    iterator end() { return iterator(data_ + size_); }

private:
    allocator_type allocator_;
    pointer data_;
    size_type size_;
    size_type capacity_;
};

#endif // DYNAMICARRAY_H