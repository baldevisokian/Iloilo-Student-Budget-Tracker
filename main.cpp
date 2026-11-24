#include <iostream>
#include "budget.h"

using namespace std;

int main() {
    BudgetData data{};

    cout << "====================================\n";
    cout << "   ILOILO STUDENT BUDGET TRACKER\n";
    cout << "====================================\n";

    data.weeklyAllowance =
        readPositiveAmount("Enter your weekly allowance: PHP ");

    int choice;

    do {
        cout << "\n====================================\n";
        cout << "   ILOILO STUDENT BUDGET TRACKER\n";
        cout << "====================================\n";
        cout << "1. Set Allowance\n";
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
                setAllowance(data);
                break;

            case 2:
                quickExpense(data);
                break;

            case 3:
                customExpense(data);
                break;

            case 4:
                viewExpenses(data);
                break;

            case 5:
                updateExpense(data);
                break;

            case 6:
                deleteExpense(data);
                break;

            case 7:
                budgetSummary(data);
                break;

            case 8:
                cout << "\nThank you for using the "
                     << "Iloilo Student Budget Tracker.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
