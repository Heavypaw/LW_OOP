#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include "figure.h"

class Array {
private:
    std::vector<Figure*> figures;

public:
    ~Array() {
        for (auto fig : figures) {
            delete fig;
        }
    }

    void add(Figure* fig) {
        figures.push_back(fig);
    }

    void remove(size_t index) {
        if (index < figures.size()) {
            delete figures[index];
            figures.erase(figures.begin() + index);
        }
    }

    Figure* get(size_t index) const {
        if (index < figures.size()) {
            return figures[index];
        }
        return nullptr;
    }

    size_t size() const {
        return figures.size();
    }

    double totalArea() const {
        double total = 0.0;
        for (const auto& fig : figures) {
            total += static_cast<double>(*fig);
        }
        return total;
    }
};

#endif 
