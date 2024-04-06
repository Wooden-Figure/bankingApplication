#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

#include <vector>

// holds information about the past investments from over a year
class YearlyResult {
private:
    int m_year; // Holds the year
    double m_yearEndBalance; // Holds the balance at the end of the year
    double m_yearEndEarnedInterest; // Holds the interest earned

public:
    // constructor for yearly result
    // the m (private data) used here b/c the private variables need initialization via constructors/ getters
    YearlyResult(int t_year, double t_yearEndBalance, double t_yearEndEarnedInterest)
            : m_year(t_year), m_yearEndBalance(t_yearEndBalance), m_yearEndEarnedInterest(t_yearEndEarnedInterest) {}
    // getter methods
    [[nodiscard]] int getYear() const { return m_year; }
    [[nodiscard]] double getYearEndBalance() const { return m_yearEndBalance; }
    [[nodiscard]] double getYearEndEarnedInterest() const { return m_yearEndEarnedInterest; }
};

// holds all the necessary information for calculating the investments
class InvestmentCalculator {
public:
    // constructor that initializes the investment calculator
    InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years);
    void calculateInvestmentGrowth();
    void displayResults() const;

private:
    double m_initialInvestment; // stores amount of money originally invested
    double m_monthlyDeposit; // amount added each month
    double m_annualInterest; // amount the investment grows
    int m_years;
    std::vector<YearlyResult> m_resultsWithoutDeposits; // this is a vector that holds the yearly result
    std::vector<YearlyResult> m_resultsWithDeposits;

    void calculateYearlyGrowth(bool t_withMonthlyDeposits); // calcs the yearly growth, the bool shows if the monthly deposits are taken into consideration
    [[nodiscard]] YearlyResult calculateYearEndResult(int t_year, double t_startingAmount, bool t_withMonthlyDeposit)
    const;
};

#endif // AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_