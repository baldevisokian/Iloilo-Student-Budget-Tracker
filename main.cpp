#include <iostream>
#include "budget.h"

using namespace std;

int main() {
    string descriptions[MAX_EXPENSES];
    double amounts[MAX_EXPENSES] = {0};
    int expenseCount = 0;
    double weeklyAllowance;
    int choice;

    cout << "====================================\n";
    cout << "   ILOILO STUDENT BUDGET TRACKER\n";
    cout << "====================================\n";

    weeklyAllowance = readPositiveAmount("Enter your weekly allowance: PHP ");

    do {
        cout << "\n====================================\n";
        cout << "   ILOILO STUDENT BUDGET TRACKER\n";
        cout << "====================================\n";
        cout << "1. Display Allowance\n";
        cout << "2. Quick Expense\n";
        cout << "3. Custom Expense\n";
        cout << "4. View Expenses\n";
        cout << "5. Update Expense\n";
        cout << "6. Delete Expense\n";
        cout << "7. Budget Summary\n";
        cout << "8. Exit\n";
        cout << "====================================\n";

        choice = readInteger("Enter your choice: ");

        switch (choice) {
            case 1:
                displayAllowance(weeklyAllowance);
                break;
            case 2:
                quickExpense(descriptions, amounts, expenseCount);
                break;
            case 3:
                customExpense(descriptions, amounts, expenseCount);
                break;
            case 4:
                viewExpenses(descriptions, amounts, expenseCount);
                break;
            case 5:
                updateExpense(descriptions, amounts, expenseCount);
                break;
            case 6:
                deleteExpense(descriptions, amounts, expenseCount);
                break;
            case 7:
                budgetSummary(weeklyAllowance, amounts, expenseCount);
                break;
            case 8:
                cout << "\nThank you for using the Iloilo Student Budget Tracker.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}
