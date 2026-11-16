
#ifndef BUDGET_H
#define BUDGET_H

#include <string>

const int MAX_EXPENSES = 100;

struct Expense {
    std::string description;
    double amount;
};

struct BudgetData {
    double weeklyAllowance;
    double totalExpenses;
    int expenseCount;
    Expense expenses[MAX_EXPENSES];
};

int readInteger(const std::string& prompt);
double readPositiveAmount(const std::string& prompt);

void setAllowance(const BudgetData& data);
void quickExpense(BudgetData& data);
void customExpense(BudgetData& data);
void viewExpenses(const BudgetData& data);
void updateExpense(BudgetData& data);
void deleteExpense(BudgetData& data);
void budgetSummary(BudgetData& data);

#endif
