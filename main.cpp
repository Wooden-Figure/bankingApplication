/* Purpose: This program, banking application (main.cpp), accepts several inputs from the user
 * involving banking information and outputs investment information. The information the program
 * accepts relates to initial investment amount, monthly deposits, and several other variables.
 * This program uses several functions and allows for scalability.
 * Author: Robert Soto
 * Created: 3/30/2024
 */

#include "InvestmentCalculator.h"
#include "InputHelpers.h"
#include <iostream>
#include <string>
#include <limits>

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int years;
    std::string userChoice;
    char newChoice;

    // shown to the user for initial investment information
    do {
        std::cout << "********************************\n"
                  << "******** Data Input ************\n"
                  << "Initial Investment Amount: $\n"
                  << "Monthly Deposit: $\n"
                  << "Annual Interest: %\n"
                  << "Number of Years: \n"
                  << "Press Enter to continue..." << std::endl;

        /*****
         * Title: std::numeric_limits::max() and std::numeric_limits::min() in C++
         * Author:Scorching
         * Date: 01 Feb, 2021
         * Availability: https://www.geeksforgeeks.org/stdnumeric_limitsmax-and-stdnumeric_limitsmin-in-c/
         *****/
        // waits for user to press enter and ignores any variables that are not enter
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // loops until the user inputs the desired information and provides an error message each time
        while (!getDoubleInput("Enter Initial Investment Amount: $", initialInvestment)) {}
        while (!getDoubleInput("Enter Monthly Deposit: $", monthlyDeposit)) {}
        while (!getDoubleInput("Enter Annual Interest: %", annualInterest)) {}
        while (!getIntInput("Enter Number of Years: ", years)) {}

        // initialized as false for when the user is asked about if they want to change anything
        bool userSatisfied = false;
        do {
            std::cout << "\n******** Input Summary ************\n"
                      << "Initial Investment Amount: $" << initialInvestment << "\n"
                      << "Monthly Deposit: $" << monthlyDeposit << "\n"
                      << "Annual Interest: %" << annualInterest << "\n"
                      << "Number of Years: " << years << "\n\n"
                      << "Do you want to change any inputs? (Y/N): " << std::endl;
            std::cin >> newChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the buffer

            if (newChoice == 'Y' || newChoice == 'y') {
                // The user wants to make changes, re-prompt for the inputs
                while (!getDoubleInput("Enter Initial Investment Amount: $", initialInvestment)) {}
                while (!getDoubleInput("Enter Monthly Deposit: $", monthlyDeposit)) {}
                while (!getDoubleInput("Enter Annual Interest: %", annualInterest)) {}
                while (!getIntInput("Enter Number of Years: ", years)) {}
            } else if (newChoice == 'N' || newChoice == 'n') {
                userSatisfied = true; // No more changes desired, continue to calculation
            } else {
                std::cout << "Invalid entry, please enter Y/y for yes or N/n for no." << std::endl;
            }
        }
        while (!userSatisfied); // exits the loop when user is true

        // displays results from the calculations
        InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, years);
        calculator.calculateInvestmentGrowth();
        calculator.displayResults();

        std::cout << "\nWould you like to calculate another investment? (Y/N): " << std::endl;
        std::cin >> userChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (userChoice == "Y" || userChoice == "y");

    std::cout << "Exiting program." << std::endl;

    return 0;
}
