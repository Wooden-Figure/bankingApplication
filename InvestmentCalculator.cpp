#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>

// defined by the constructor in the investmentcalculator.h file, initializes all the below
InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double
t_annualInterest, int t_years)
        : m_initialInvestment(t_initialInvestment),
          m_monthlyDeposit(t_monthlyDeposit), m_annualInterest(t_annualInterest),
          m_years(t_years) {}

// calculates the growth both with and without monthly deposits
void InvestmentCalculator::calculateInvestmentGrowth() {
    calculateYearlyGrowth(false); // without additional deposits.
    calculateYearlyGrowth(true);  // with additional deposits.
}

// displays the results for the calculations
void InvestmentCalculator::displayResults() const {
    std::cout << std::fixed << std::setprecision(2); // formats numbers to show two decimal places.
    std::cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    for (const auto& result : m_resultsWithoutDeposits) {
        std::cout << result.getYear() << "\t$" << result.getYearEndBalance() << "\t\t\t$" <<
        result.getYearEndEarnedInterest() << "\n";
    }

    std::cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    for (const auto& result : m_resultsWithDeposits) {
        std::cout << result.getYear() << "\t$" << result.getYearEndBalance() << "\t\t\t$" <<
        result.getYearEndEarnedInterest() << "\n";
    }
}

// this function takes into consideration the years of the investment, the boolean statement helps determine
// which type of deposit to use/ or not use
void InvestmentCalculator::calculateYearlyGrowth(bool t_withMonthlyDeposits) {
    // updates the current balance to be the initial investment and updates with the increase in the account
    double currentBalance = m_initialInvestment;
    // the loop iterates over the years, using the year mark as the incremental portion
    for (int year = 1; year <= m_years; ++year) {
        auto result = calculateYearEndResult(year, currentBalance,
                                             t_withMonthlyDeposits);
        currentBalance = result.getYearEndBalance();
        // conditional statement determines which type of deposit occurs and depending upon the result
        // adds the result accordingly
        if (t_withMonthlyDeposits) {
            m_resultsWithDeposits.push_back(result);
        } else {
            m_resultsWithoutDeposits.push_back(result);
        }
    }
}

YearlyResult InvestmentCalculator::calculateYearEndResult(int t_year, double t_startingAmount, bool
t_withMonthlyDeposit) const {
    double balance = t_startingAmount;
    double totalInterest = 0.0;
    for (int month = 1; month <= 12; ++month) {
        if (t_withMonthlyDeposit) {
            balance += m_monthlyDeposit;
        }
        double monthlyInterest = (balance * (m_annualInterest / 100)) / 12;
        balance += monthlyInterest;
        totalInterest += monthlyInterest;
    }

    return {t_year, balance, totalInterest};
}
