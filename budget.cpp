#include <iostream>
#include <iomanip>
#include <string>
#include "budget.h"

using namespace std;

int readInteger(const string& prompt) {
    int value;

    cout << prompt;
    if (cin >> value) {
        cin.ignore(10000, '\n');
        return value;
    } else {
        cout << "Invalid input. Please enter a whole number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
}

double readPositiveAmount(const string& prompt) {
    double amount;

    while (true) {
        cout << prompt;
        if (cin >> amount) {
            cin.ignore(10000, '\n');
            if (amount > 0) {
                return amount;
            } else {
                cout << "Invalid amount. Enter a number greater than 0.\n";
            }
        } else {
            cout << "Invalid amount. Enter a number greater than 0.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

string readDescription(const string& prompt) {
    string description;

    do {
        cout << prompt;
        getline(cin, description);
        if (description.empty()) {
            cout << "Description cannot be empty.\n";
        }
    } while (description.empty());

    return description;
}

void addExpense(string descriptions[], double amounts[], int& expenseCount,
                const string& description, double amount) {
    if (expenseCount >= MAX_EXPENSES) {
        cout << "Expense limit reached.\n";
    } else {
        descriptions[expenseCount] = description;
        amounts[expenseCount] = amount;
        expenseCount++;
        cout << "Expense added successfully.\n";
    }
}

bool validRecordNumber(int number, int expenseCount) {
    if (number >= 1 && number <= expenseCount) {
        return true;
    } else {
        return false;
    }
}

void displayAllowance(double weeklyAllowance) {
    cout << fixed << setprecision(2);
    cout << "Your weekly allowance is PHP " << weeklyAllowance << ".\n";
}

void quickExpense(string descriptions[], double amounts[], int& expenseCount) {
    int choice;
    string description;
    double amount = 0;

    do {
        cout << "\n--- QUICK EXPENSE ---\n";
        cout << "1. Jeepney Fare - PHP 15\n";
        cout << "2. Batchoy - PHP 80\n";
        cout << "3. Printing - PHP 5\n";
        cout << "4. Return to Main Menu\n";

        choice = readInteger("Choose an expense: ");

        switch (choice) {
            case 1:
                description = "Jeepney Fare";
                amount = 15;
                addExpense(descriptions, amounts, expenseCount, description, amount);
                break;
            case 2:
                description = "Batchoy";
                amount = 80;
                addExpense(descriptions, amounts, expenseCount, description, amount);
                break;
            case 3:
                description = "Printing";
                amount = 5;
                addExpense(descriptions, amounts, expenseCount, description, amount);
                break;
            case 4:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice < 1 || choice > 4);
}

void customExpense(string descriptions[], double amounts[], int& expenseCount) {
    if (expenseCount >= MAX_EXPENSES) {
        cout << "Expense limit reached.\n";
    } else {
        cout << "\n--- CUSTOM EXPENSE ---\n";
        string description = readDescription("Enter expense description: ");
        double amount = readPositiveAmount("Enter expense amount: PHP ");
        addExpense(descriptions, amounts, expenseCount, description, amount);
    }
}

void viewExpenses(const string descriptions[], const double amounts[], int expenseCount) {
    cout << "\n--- RECORDED EXPENSES ---\n";

    if (expenseCount == 0) {
        cout << "No expenses recorded.\n";
    } else {
        cout << fixed << setprecision(2);
        for (int i = 0; i < expenseCount; i++) {
            cout << i + 1 << ". " << descriptions[i]
                 << " - PHP " << amounts[i] << "\n";
        }
    }
}

void updateExpense(string descriptions[], double amounts[], int expenseCount) {
    cout << "\n--- UPDATE EXPENSE ---\n";

    if (expenseCount == 0) {
        cout << "No expenses recorded.\n";
    } else {
        viewExpenses(descriptions, amounts, expenseCount);
        int number = readInteger("Enter record number to update: ");

        if (validRecordNumber(number, expenseCount)) {
            descriptions[number - 1] = readDescription("Enter new description: ");
            amounts[number - 1] = readPositiveAmount("Enter new amount: PHP ");
            cout << "Expense updated successfully.\n";
        } else {
            cout << "Invalid record number. Please try again.\n";
        }
    }
}

void deleteExpense(string descriptions[], double amounts[], int& expenseCount) {
    cout << "\n--- DELETE EXPENSE ---\n";

    if (expenseCount == 0) {
        cout << "No expenses recorded.\n";
    } else {
        viewExpenses(descriptions, amounts, expenseCount);
        int number = readInteger("Enter record number to delete: ");

        if (validRecordNumber(number, expenseCount)) {
            for (int i = number - 1; i < expenseCount - 1; i++) {
                descriptions[i] = descriptions[i + 1];
                amounts[i] = amounts[i + 1];
            }
            expenseCount--;
            cout << "Expense deleted successfully.\n";
        } else {
            cout << "Invalid record number. Please try again.\n";
        }
    }
}

void budgetSummary(double weeklyAllowance, const double amounts[], int expenseCount) {
    double totalExpenses = 0;

    for (int i = 0; i < expenseCount; i++) {
        totalExpenses = totalExpenses + amounts[i];
    }

    double remainingAllowance = weeklyAllowance - totalExpenses;

    cout << fixed << setprecision(2);
    cout << "\n--- BUDGET SUMMARY ---\n";
    cout << "Weekly allowance: PHP " << weeklyAllowance << "\n";
    cout << "Total expenses: PHP " << totalExpenses << "\n";
    cout << "Remaining allowance: PHP " << remainingAllowance << "\n";

    if (remainingAllowance <= 100) {
        cout << "Warning: Your remaining allowance is low!\n";
    } else {
        cout << "Your remaining allowance is above PHP 100.\n";
    }
}
