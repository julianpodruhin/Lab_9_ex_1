#include <iostream>
#include <stdexcept>
#include <cmath>

class Triangle {
public:
    Triangle(double a, double b, double c) {
        if (!isValid(a, b, c)) {
            throw std::invalid_argument("Invalid triangle sides");
        }
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;
    }
    double getPerimeter() const {
        return sides[0] + sides[1] + sides[2];
    }
    double getArea() const {
        double s = getPerimeter() / 2.0;
        return std::sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
    }
private:
    double sides[3];
    bool isValid(double a, double b, double c) const {
        return a > 0 && b > 0 && c > 0 &&
            a + b > c && a + c > b && b + c > a;
    }
};

int main() {
    try {
        Triangle t1(3, 4, 5);
        std::cout << "Perimeter: " << t1.getPerimeter() << std::endl;
        std::cout << "Area: " << t1.getArea() << std::endl;
        // Throws an exception because 1 + 2 < 5
        Triangle t2(1, 2, 5);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}