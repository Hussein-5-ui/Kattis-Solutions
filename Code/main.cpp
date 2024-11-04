#include <iostream>
#include <string>
#include <climits>

const unsigned long MAX = (1 << 31);

bool isWithinBounds(const std::string& numStr) {
    try {
        unsigned long num = std::stoul(numStr);
        return num < MAX;
    } catch (const std::out_of_range&) {
        return false;
    }
}

std::string valid(const std::string& d1, const std::string& d2, const std::string& d3, const std::string& op) {
    long l1 = std::stol(d1);
    long l2 = std::stol(d2);
    long l3 = std::stol(d3);
    //checks for numbers out of range
    if (l1 >= MAX || l2 >= MAX || l3 >= MAX || l1 < 0 || l2 < 0 || l3 < 0) return "";
    //checks if the new numbers with the swapped prefixes are mathematically correct.
    if (op == "+") {
        if (l1 + l2 == l3) {
            return d1 + " + " + d2 + " = " + d3;
        }
    } else {
        if (l1 * l2 == l3) {
            return d1 + " * " + d2 + " = " + d3;
        }
    }
    return "";
}
//main logic
std::string solve(const std::string& d1, const std::string& d2, const std::string& d3, const std::string& op) {
    // Direct check for the initial operands
    std::string result = valid(d1, d2, d3, op);
    if (!result.empty()) return result;

    // All swaps of d1 and d2 prefixes
    for (size_t i = 1; i < d1.size(); i++) {
        for (size_t j = 1; j < d2.size(); j++) {
            std::string newD1 = d2.substr(0, j) + d1.substr(i);
            std::string newD2 = d1.substr(0, i) + d2.substr(j);
            result = valid(newD1, newD2, d3, op);
            if (!result.empty()) return result;
        }
    }

    // All swaps of d1 and d3 prefixes
    for (size_t i = 1; i < d1.size(); i++) {
        for (size_t k = 1; k < d3.size(); k++) {
            std::string newD1 = d3.substr(0, k) + d1.substr(i);
            std::string newD2 = d2;
            result = valid(newD1, newD2, d1.substr(0, i) + d3.substr(k), op);
            if (!result.empty()) return result;
        }
    }

    // All swaps of d2 and d3 prefixes
    for (size_t j = 1; j < d2.size(); j++) {
        for (size_t k = 1; k < d3.size(); k++) {
            std::string newD1 = d1;
            std::string newD2 = d3.substr(0, k) + d2.substr(j);
            std::string newResult = d2.substr(0, j) + d3.substr(k);
            result = valid(newD1, newD2, newResult, op);
            if (!result.empty()) return result;
        }
    }
    return " ";
}

int main() {
    std::string firstOperand, operator_, secondOperand, equalSign, result;
    std::cin >> firstOperand >> operator_ >> secondOperand >> equalSign >> result;

    std::cout << solve(firstOperand, secondOperand, result, operator_);
    return 0;
}