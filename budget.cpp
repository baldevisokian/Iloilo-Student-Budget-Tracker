
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "budget.h"

using namespace std;

int readInteger(const string& prompt) {
    string input;
    int value;
    char extra;

    cout << prompt;
    getline(cin, input);

    stringstream ss(input);

    if (!(ss >> value) || (ss >> extra)) {
        return -1;
    }

    return value;
}

double readPositiveAmount(const string& prompt) {
    string input;
    double amount;
    char extra;

    while (true) {
        cout << prompt;
        getline(cin, input);

        stringstream ss(input);

        if ((ss >> amount) && !(ss >> extra) && amount > 0) {
            return amount;
        }

        cout << "Invalid amount. Enter a number greater than 0.\n";
    }
}

static string readDescription(const string& prompt) {
    string description;

    while (true) {
        cout << prompt;
        getline(cin, description);

        if (description.find_first_not_of(" \t") != string::npos) {
            return description;
        }

        cout << "Description cannot be empty.\n";
    }
}

static void addExpense(BudgetData& data,
                       const string& description,
                       double amount) {
    if (data.expenseCount >= MAX_EXPENSES) {
        cout << "Expense limit reached.\n";
        return;
    }

    data.expenses[data.expenseCount].description = description;
    data.expenses[data.expenseCount].amount = amount;
    data.expenseCount++;

    cout << "Expense added successfully.\n";
}

static bool validRecord(const BudgetData& data, int number) {
    return number >= 1 && number <= data.expenseCount;
}

void setAllowance(const BudgetData& data) {
    cout << fixed << setprecision(2);
    cout << "Weekly allowance is already set at PHP "
         << data.weeklyAllowance << ".\n";
}

void quickExpense(BudgetData& data) {
    cout << "\n--- QUICK EXPENSE ---\n";
    cout << "1. Jeepney Fare - PHP 15\n";
    cout << "2. Batchoy - PHP 80\n";
    cout << "3. Printing - PHP 5\n";

    int choice = readInteger("Choose an expense: ");

    switch (choice) {
        case 1:
            addExpense(data, "Jeepney Fare", 15);
            break;

        case 2:
            addExpense(data, "Batchoy", 80);
            break;

        case 3:
            addExpense(data, "Printing", 5);
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void customExpense(BudgetData& data) {
    cout << "\n--- CUSTOM EXPENSE ---\n";

    string description = readDescription("Enter expense description: ");
    double amount = readPositiveAmount("Enter expense amount: PHP ");

    addExpense(data, description, amount);
}

void viewExpenses(const BudgetData& data) {
    cout << "\n--- RECORDED EXPENSES ---\n";

    if (data.expenseCount == 0) {
        cout << "No expenses recorded.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < data.expenseCount; i++) {
        cout << i + 1 << ". "
             << data.expenses[i].description
             << " - PHP "
             << data.expenses[i].amount << "\n";
    }
}

void updateExpense(BudgetData& data) {
    cout << "\n--- UPDATE EXPENSE ---\n";
    viewExpenses(data);

    if (data.expenseCount == 0) {
        return;
    }

    int number = readInteger("Enter record number to update: ");

    if (!validRecord(data, number)) {
        cout << "Invalid record number. Please try again.\n";
        return;
    }

    string description = readDescription("Enter new description: ");
    double amount = readPositiveAmount("Enter new amount: PHP ");

    data.expenses[number - 1].description = description;
    data.expenses[number - 1].amount = amount;

    cout << "Expense updated successfully.\n";
}

void deleteExpense(BudgetData& data) {
    cout << "\n--- DELETE EXPENSE ---\n";
    viewExpenses(data);

    if (data.expenseCount == 0) {
        return;
    }

    int number = readInteger("Enter record number to delete: ");

    if (!validRecord(data, number)) {
        cout << "Invalid record number. Please try again.\n";
        return;
    }

    for (int i = number - 1; i < data.expenseCount - 1; i++) {
        data.expenses[i] = data.expenses[i + 1];
    }

    data.expenseCount--;

    cout << "Expense deleted successfully.\n";
}

void budgetSummary(BudgetData& data) {
    data.totalExpenses = 0;

    for (int i = 0; i < data.expenseCount; i++) {
        data.totalExpenses += data.expenses[i].amount;
    }

    double remainingAllowance =
        data.weeklyAllowance - data.totalExpenses;

    cout << fixed << setprecision(2);
    cout << "\n--- BUDGET SUMMARY ---\n";
    cout << "Weekly allowance: PHP "
         << data.weeklyAllowance << "\n";
    cout << "Total expenses: PHP "
         << data.totalExpenses << "\n";
    cout << "Remaining allowance: PHP "
         << remainingAllowance << "\n";

    if (remainingAllowance <= 100) {
        cout << "Warning: Your remaining allowance is low!\n";
    }
}
