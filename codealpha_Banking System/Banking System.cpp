#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};
class Account {
public:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;
    Account(int accNo) {
        accountNumber = accNo;
        balance = 0.0;
    }
    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit Successful!\n";
    }
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal Successful!\n";
        return true;
    }
    void showTransactions() {
        if (transactions.empty()) {
            cout << "No transactions available.\n";
            return;
        }
        cout << "Transaction History:\n";
        for (auto &t : transactions) {
            cout << t.type << " : " << t.amount << endl;
        }
    }
};
class Customer {
public:
    string name;
    Account* account;
    Customer(string n, int accNo) {
        name = n;
        account = new Account(accNo);
    }
};
int main() {
    string name;
    int accNo;
    double amount;
    int choice;
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Account Number: ";
    cin >> accNo;
    Customer customer(name, accNo);
    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Balance\n";
        cout << "4. View Transactions\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            customer.account->deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            customer.account->withdraw(amount);
            break;
        case 3:
            cout << "Current Balance: " << customer.account->balance << endl;
            break;
        case 4:
            customer.account->showTransactions();
            break;
        case 5:
            cout << "Thank you for using Banking System.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}