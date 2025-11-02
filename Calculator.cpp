#include <iostream>
#include <limits>
#include <string>
#include <cmath>

namespace {

// Prompt the user for a floating-point number and reject invalid input.
double promptForNumber(const std::string& label) {
    while (true) {
        std::cout << "Enter " << label << ": ";
        double value{};
        if (std::cin >> value) {
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number. Please try again.\n";
    }
}

// Ask the user which arithmetic operation to perform; includes quit option.
char promptForOperation() {
    while (true) {
        std::cout << "Choose operation (+, -, *, /, %, q to quit): ";
        char op{};
        if (std::cin >> op) {
            switch (op) {
                case '+':  // Addition
                case '-':  // Subtraction
                case '*':  // Multiplication
                case '/':  // Division
                case '%':  // Modulo (floating-point remainder)
                case 'q':  // Quit (lowercase)
                case 'Q':  // Quit (uppercase)
                    return op;
                default:
                    break;
            }
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Unsupported operation. Please choose one of +, -, *, /, %, or q.\n";
    }
}

// Execute the arithmetic specified by op on lhs and rhs.
double calculate(double lhs, double rhs, char op) {
    switch (op) {
        case '+':  // Addition
            return lhs + rhs;
        case '-':  // Subtraction
            return lhs - rhs;
        case '*':  // Multiplication
            return lhs * rhs;
        case '/':  // Division with zero check
            if (rhs == 0.0) {
                throw std::runtime_error("Division by zero is undefined.");
            }
            return lhs / rhs;
        case '%':  // Floating-point modulo
            if (rhs == 0.0) {
                throw std::runtime_error("Modulo by zero is undefined.");
            }
            return std::fmod(lhs, rhs);
        default:
            throw std::runtime_error("Unsupported operation.");
    }
}

}  // namespace

int main() {
    // Display a simple header.
    std::cout << "Simple Calculator\n";
    std::cout << "-----------------\n";

    // Seed the running result with the user's first number.
    double result = promptForNumber("the first number");
    std::cout << "Current result: " << result << "\n";

    while (true) {
        char operation = promptForOperation();
        if (operation == 'q' || operation == 'Q') {
            break;
        }

        // Gather the next operand and immediately compute the new result.
        double nextNumber = promptForNumber("the next number");

        try {
            // Compute and show the result of the selected operation.
            result = calculate(result, nextNumber, operation);
            std::cout << "Result: " << result << "\n";
        } catch (const std::exception& ex) {
            std::cout << "Error: " << ex.what() << "\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
