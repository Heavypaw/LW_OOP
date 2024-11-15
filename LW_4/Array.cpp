#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>

template <typename T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t size_;
    size_t capacity_;

public:
    Array() : size_(0), capacity_(10) {
        data = std::make_shared<T[]>(capacity_);
    }

    Array(size_t initialCapacity) : size_(0), capacity_(initialCapacity) {
        data = std::make_shared<T[]>(capacity_);
    }

    void add(const T& item) {
        if (size_ >= capacity_) {
            resize(capacity_ * 2);
        }
        data[size_++] = item;
    }

    void remove(size_t index) {
        if (index < size_) {
            for (size_t i = index; i < size_ - 1; ++i) {
                data[i] = std::move(data[i + 1]);
            }
            --size_;
        }
    }

    T& get(size_t index) const {
        if (index < size_) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    size_t size() const {
        return size_;
    }

    void resize(size_t newCapacity) {
        std::shared_ptr<T[]> newData = std::make_shared<T[]>(newCapacity);
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = std::move(data[i]);
        }
        data = newData;
        capacity_ = newCapacity;
    }
};

#endif // ARRAY_H
