#include <iostream>
#include <cstddef>
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"

int main() {
    Array figures;

    std::cout << "Enter number of figures: ";
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter figure type (1 - Triangle, 2 - Square, 3 - Rectangle): ";
        int type;
        std::cin >> type;

        Figure* fig = nullptr;
        switch (type) {
            case 1:
                fig = new Triangle();
                break;
            case 2:
                fig = new Square();
                break;
            case 3:
                fig = new Rectangle();
                break;
            default:
                std::cout << "Invalid figure type\n";
                continue;
        }

        std::cin >> *fig;
        figures.add(fig);
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        Figure* fig = figures.get(i);
        std::cout << "Figure " << i << ": " << *fig << "\n";
        auto center = fig->center();
        std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "Area: " << static_cast<double>(*fig) << "\n";
    }

    std::cout << "Total area: " << figures.totalArea() << "\n";

    std::cout << "Enter index of figure to remove: ";
    size_t index;
    std::cin >> index;
    figures.remove(index);

    return 0;
}
