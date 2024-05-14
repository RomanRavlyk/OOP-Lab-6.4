#include <iostream>
#include <stdexcept>
#include "Vector.h"

int main() {
    try {
        Vector<int> V(5), U(5), Z(5), T(5);

        std::cin >> V;
        std::cin >> U;

        T = V + U;
        std::cout << "Sum of vectors:" << std::endl;
        std::cout << T;

        Z += V;
        Z += U;
        std::cout << "Sum of vectors:" << std::endl;
        std::cout << Z;

        std::cout << "Result of adding scalar 5 to vector V: " << V + 5 << std::endl;

        std::cout << "Minimum element = " << Z.extract("min") << std::endl;

        Z.sort("up");
        std::cout << "Sorted:" << std::endl;
        std::cout << Z;

        std::cout << "Norm = " << Z.norm() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
