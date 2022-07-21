#include <bits/stdc++.h>
using namespace std;
// 18467
class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;

protected:
    int balance;

private:
    string password;

public:
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand() % 100000000;
        this->balance = 0;
        cout << "\nYour account no is " << this->account_number << endl;
    }
    int show_balance(string password)
    {
        if (this->password == password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
        return 0;
    }
    int deposit(int amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
            return amount;
        }
        return 0;
    };
    int withdraw(int amount)
    {
        if (this->balance >= amount)
        {
            this->balance -= amount;
            return amount;
        }
        return 0;
    };
};
void *create_account();
void *find_account(BankAccount **all_accounts, int total_account);
int main()
{
    int total_account = 0;
    int command = 1;
    int account_number;
    int balance;
    string password = "";
    BankAccount **all_accounts = new BankAccount *[100];
    BankAccount *account;

    while (command)
    {
        switch (command)
        {
            {
            case 1:
                cout << "\n\t***ALL OPTIONS***\n\n";
                cout << "0. Exit" << endl;
                cout << "1. Show All Options" << endl;
                cout << "2. Create Account" << endl;
                cout << "3. Show Info" << endl;
                cout << "4. Deposit" << endl;
                cout << "5. Withdraw" << endl;
                cout << "Please enter : ";
                cin >> command;
                break;
            case 2:
                account = (BankAccount *)create_account();
                all_accounts[total_account] = account;
                total_account++;
                command = 1;
                break;
            case 3:
                if (total_account == 0)
                {
                    cout << "Account Not Created" << endl;
                    command = 1;
                    break;
                }
                account = (BankAccount *)find_account(all_accounts, total_account);

                if (account == NULL)
                {
                    cout << "Account Not Found" << endl;
                    command = 1;
                    break;
                }
                cout << "Enter Password: ";
                cin >> password;

                balance = account->show_balance(password);
                cout << "\n\t***Info***\n\n";
                cout << "Acccount No : " << account->account_number << endl;
                cout << "Name: " << account->account_holder << endl;
                cout << "Age: " << account->age << endl;
                cout << "Address: " << account->address << endl;
                if (balance == -1)
                    cout
                        << "Invalid password" << endl;
                else
                    cout << "Balance: " << balance << endl;
                cout << "\n";
                command = 1;

                break;
            case 4:
                account = (BankAccount *)find_account(all_accounts, total_account);
                cout << "Enter Amount : ";
                cin >> balance;
                command = 1;
                balance = account->deposit(balance);
                if (balance)
                {
                    cout << "Deposit Successful" << endl;
                }
                else
                {
                    cout << "Deposit Failed" << endl;
                }
                command = 1;

                break;
            case 5:
                account = (BankAccount *)find_account(all_accounts, total_account);
                cout << "Enter Amount : ";
                cin >> balance;
                command = 1;
                balance = account->withdraw(balance);
                if (balance)
                {
                    cout << "Withdraw Successful" << endl;
                }
                else
                {
                    cout << "Withdraw Failed" << endl;
                }
                command = 1;
                break;
            default:
                cout << "Invalid command" << endl;
                command = 1;
                break;
            }
        }
    }

    return 0;
}
void *create_account()
{
    cout << "\n\t*** Create Account ***\n\n";
    string account_holder;
    string address;
    int age;
    string password;

    cout << "Enter your name : ";
    getline(cin, account_holder);
    getline(cin, account_holder);

    cout << "Enter your address : ";
    getline(cin, address);
    cout << "Enter your password : ";
    getline(cin, password);
    cout << "Enter your age : ";
    cin >> age;

    BankAccount *account = new BankAccount(account_holder, address, age, password);
    cout << "Successfully created account\n\n";
    return account;
}
void *find_account(BankAccount **all_accounts, int total_account)
{
    int account_number;
    cout << "Enter Account Number: ";
    cin >> account_number;
    BankAccount *account;
    account = NULL;
    for (int i = 0; i < total_account; i++)
    {
        if (all_accounts[i]->account_number == account_number)
        {
            account = all_accounts[i];
        }
    }
    return account;
}