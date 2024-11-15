#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    std::cout << "Enter number of figures: ";
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter figure type (1 - Triangle, 2 - Square, 3 - Rectangle): ";
        int type;
        std::cin >> type;

        std::shared_ptr<Figure<int>> fig;
        switch (type) {
            case 1:
                fig = std::make_shared<Triangle<int>>();
                break;
            case 2:
                fig = std::make_shared<Square<int>>();
                break;
            case 3:
                fig = std::make_shared<Rectangle<int>>();
                break;
            default:
                std::cout << "Invalid figure type\n";
                continue;
        }

        std::cin >> *fig;
        figures.add(fig);
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        std::shared_ptr<Figure<int>> fig = figures.get(i);
        std::cout << "Figure " << i << ": " << *fig << "\n";
        auto center = fig->center();
        std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "Area: " << static_cast<double>(*fig) << "\n";
    }

    double totalArea = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        totalArea += static_cast<double>(*figures.get(i));
    }
    std::cout << "Total area: " << totalArea << "\n";

    std::cout << "Enter index of figure to remove: ";
    size_t index;
    std::cin >> index;
    figures.remove(index);

    return 0;
}