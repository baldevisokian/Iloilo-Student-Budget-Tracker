#ifndef BUDGET_H
#define BUDGET_H

#include <string>

const int MAX_EXPENSES = 100;

int readInteger(const std::string& prompt);
double readPositiveAmount(const std::string& prompt);
std::string readDescription(const std::string& prompt);

void displayAllowance(double weeklyAllowance);
void quickExpense(std::string descriptions[], double amounts[], int& expenseCount);
void customExpense(std::string descriptions[], double amounts[], int& expenseCount);
void viewExpenses(const std::string descriptions[], const double amounts[], int expenseCount);
void updateExpense(std::string descriptions[], double amounts[], int expenseCount);
void deleteExpense(std::string descriptions[], double amounts[], int& expenseCount);
void budgetSummary(double weeklyAllowance, const double amounts[], int expenseCount);

#endif
