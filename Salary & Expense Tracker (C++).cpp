#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const vector<string> months = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int main() {
    map<int, map<int, map<string, double>>> expenses;
    map<int, map<int, double>> salaries;

    double carry = 0.0, total_exp = 0.0, total_save = 0.0;

    ofstream csv("expense_report.csv");
    csv << "Year,Month,Salary,CarryForward,TotalBudget,TotalExpense,MonthlySavings\n";

    cout << "Welcome to the Monthly Salary & Expense Tracker (By Mr. K.Konar)\n\n";

    string more = "yes";
    while (more == "yes") {
        int y, m;
        double sal;
        cout << "Enter year (e.g., 2025): ";
        cin >> y;

        cout << "\nSelect month:\n";
        for (int i = 0; i < 12; ++i) cout << "  " << (i + 1) << ". " << months[i] << "\n";

        cout << "Enter month number (1-12): ";
        cin >> m;
        cin.ignore();

        cout << "Enter salary for " << months[m - 1] << " " << y << " (Rs): ";
        cin >> sal;
        cin.ignore();

        salaries[y][m] = sal;

        string add_more = "yes";
        while (add_more == "yes") {
            string item;
            double amt;
            cout << "  Enter expense item (e.g, Rent,Food,): ";
            getline(cin, item);
            cout << "  Enter amount for " << item << " (Rs): ";
            cin >> amt;
            cin.ignore();

            expenses[y][m][item] += amt;

            cout << "  Add more items in " << months[m - 1] << "? (yes/no): ";
            getline(cin, add_more);
        }

        double budget = carry + sal;
        double m_exp = 0.0;

        cout << "\n--- Report for " << months[m - 1] << " " << y << " ---\n";

        for (auto& e : expenses[y][m]) {
            cout << "  - " << e.first << ": Rs " << fixed << setprecision(2) << e.second << "\n";
            m_exp += e.second;
        }

        double save = budget - m_exp;
        carry = save;

        cout << "  Salary: Rs " << sal << "\n";
        cout << "  Previous Savings: Rs " << (budget - sal) << "\n";
        cout << "  Total Budget: Rs " << budget << "\n";
        cout << "  Expenses: Rs " << m_exp << "\n";
        cout << "  Savings: Rs " << save << "\n\n";

        csv << y << "," << months[m - 1] << "," << sal << ","
            << (budget - sal) << "," << budget << ","
            << m_exp << "," << save << "\n";

        total_exp += m_exp;
        total_save = carry;

        cout << "Add another month? (yes/no): ";
        getline(cin, more);
        cout << "\n";
    }

    csv.close();

    cout << "=== Overall Summary ===\n";
    cout << "Grand Total Expenses: Rs " << total_exp << "\n";
    cout << "Final Remaining Savings: Rs " << total_save << "\n";
    cout << "CSV exported to 'expense_report.csv'\n";

    return 0;
}
