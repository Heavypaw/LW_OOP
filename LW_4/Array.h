#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>

template <typename T>
class Array {
private:
    std::vector<T> data;

public:
    Array() = default;

    void add(const T& item) {
        data.push_back(item);
    }

    void remove(size_t index) {
        if (index < data.size()) {
            data.erase(data.begin() + index);
        }
    }

    T& get(size_t index) {
        if (index < data.size()) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    const T& get(size_t index) const {
        if (index < data.size()) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    size_t size() const {
        return data.size();
    }
};

#endif // ARRAY_H