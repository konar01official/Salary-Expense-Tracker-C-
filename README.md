# 💸 Salary & Expense Tracker (C++) 🧾

A lightweight, interactive **command-line application** built in **C++** to help users **track monthly expenses**, **visualize financial behavior**, and **calculate annual savings** based on a fixed salary.

Designed for individuals looking to **develop budgeting discipline** and gain a quick overview of where their money is going — all from the terminal!

---

## 🚀 Features

✅ Track categorized expenses across multiple months  
✅ Dynamic input for expenses and categories  
✅ Instant calculations for:
- Total Expenses 💸  
- Net Annual Savings 💰  
✅ Clean, structured output with formatting  
✅ Error-handling for negative inputs  
✅ Easy to compile and run from any C++ IDE or terminal

---

## 🛠 Tech Stack

| Component         | Description                                |
|------------------|--------------------------------------------|
| **Language**      | C++                                        |
| **Libraries Used**| `iostream`, `map`, `string`, `iomanip`, `fstream` |
| **Paradigm**      | Procedural Programming                     |
| **Interface**     | Command-Line Interface (CLI)               |

---

## 📊 How It Works

1. User enters the **year and month**
2. Inputs **salary** for that month (can be 0)
3. Enters multiple **expense items and their amounts**
4. Program calculates:
   - Monthly total expenses
   - Remaining savings
   - Carry-forward savings to the next month
5. Monthly report is shown immediately
6. At the end, a **final overall report** is displayed

---

## 📤 CSV Export

Each monthly entry is automatically saved to a file named `expense_report.csv`  
This can be analyzed later in **Excel** or **Python (pandas, matplotlib)**.

Example format:

```csv
Year,Month,Salary,CarryForward,TotalBudget,TotalExpense,MonthlySavings
2024,January,30000,0,30000,20000,10000
2024,February,28000,10000,38000,16000,22000

