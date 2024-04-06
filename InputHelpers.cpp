/* This InputHelpers.cpp serves in removing the input buffer and returning numbers as needed as
well as handling input validation */

#include "InputHelpers.h"
#include <iostream>
#include <limits>

// serves as an input validation w/ clear removing any error that occurs, while ignore does not begin working until it
// encounters a newline character and then clears any remaining characters with the two of them
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// if the statement returns true, the function allows the user to continue and provides input validation if the user
// does not enter the desired answer
bool getDoubleInput(const std::string& t_prompt, double& t_value) {
    std::cout << t_prompt;
    std::cin >> t_value;
    // when the user a number besides a double, this is prompted
    if (std::cin.fail()) {
        clearInputBuffer();
        std::cout << "Invalid entry. Please enter a numeric value.\n";
        return false;
    }
    return true;
}

// does similarly as to the last function
bool getIntInput(const std::string& t_prompt, int& t_value) {
    std::cout << t_prompt;
    std::cin >> t_value;
    if (std::cin.fail()) {
        clearInputBuffer();
        std::cout << "Invalid entry. Please enter an integer value.\n";
        return false;
    }
    return true;
}
