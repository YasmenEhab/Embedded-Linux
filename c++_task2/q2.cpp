#include <iostream>
#include <cmath>

class Calculator {
private:
    // Private member functions for the operations
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero is undefined.\n";
            return 0;
        }
        return a / b;
    }

    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }

    double squareRoot(double a) {
        if (a < 0) {
            std::cerr << "Error: Square root of a negative number is undefined.\n";
            return 0;
        }
        return std::sqrt(a);
    }

public:
    // Public function to interface with the user
    void calculate() {
        double num1, num2, result;
        char operation;

        std::cout << "Enter the first number: ";
        std::cin >> num1;
        std::cout << "Enter an operator (+, -, *, /, ^, S for square root): ";
        std::cin >> operation;

        switch (operation) {
            case '+':
                std::cout << "Enter the second number: ";
                std::cin >> num2;
                result = add(num1, num2);
                std::cout << "Result: " << result << "\n";
                break;
            case '-':
                std::cout << "Enter the second number: ";
                std::cin >> num2;
                result = subtract(num1, num2);
                std::cout << "Result: " << result << "\n";
                break;
            case '*':
                std::cout << "Enter the second number: ";
                std::cin >> num2;
                result = multiply(num1, num2);
                std::cout << "Result: " << result << "\n";
                break;
            case '/':
                std::cout << "Enter the second number: ";
                std::cin >> num2;
                result = divide(num1, num2);
                std::cout << "Result: " << result << "\n";
                break;
            case '^':
                std::cout << "Enter the exponent: ";
                std::cin >> num2;
                result = power(num1, num2);
                std::cout << "Result: " << result << "\n";
                break;
            case 'S':
                result = squareRoot(num1);
                std::cout << "Result: " << result << "\n";
                break;
            default:
                std::cerr << "Error: Invalid operator.\n";
        }
    }
};

int main() {
    Calculator calc;
    calc.calculate();
    return 0;
}

