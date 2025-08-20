#include <iostream>
using namespace std;
class Account {
public:
    int accountNumber;
    string name;
    double balance;
    Account(int accNo, string n, double bal) {
        accountNumber = accNo;
        name = n;
        balance = bal;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " to " << name << "'s account.\n";
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from " << name << "'s account.\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }
    void transfer(Account &other, double amount) {
        if (amount <= balance) {
            balance -= amount;
            other.balance += amount;
            cout << "Transferred " << amount << " from " << name 
                 << " to " << other.name << ".\n";
        } else {
            cout << "Insufficient balance for transfer!\n";
        }
    }
    void showBalance() {
        cout << name << "'s Account Balance: " << balance << endl;
    }
};

int main() {
    Account acc1(101, "FARRUKH", 155000);
    Account acc2(102, "ZOHAIB", 222000);

    acc1.showBalance();
    acc2.showBalance();
    acc1.deposit(500);
    acc1.withdraw(300);
    acc1.transfer(acc2, 200);

    cout << "\n--- Updated Balances ---\n";
    acc1.showBalance();
    acc2.showBalance();

    return 0;
}
