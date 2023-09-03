#include <iostream>
#include <list>

class Account {
public:
    std::string getAccountDetails() {
        return "Balance: " + std::to_string(balance) + "\nUsername: " + username + "\nPassword: " + password + "\nEmail: " + email;
    }

    void setAccountDetails(float newBalance, std::string newUsername, std::string newPassword, std::string newEmail) {
        balance = newBalance;
        username = newUsername;
        password = newPassword;
        email = newEmail;
    };

private:
    float balance{};
    std::string username;
    std::string password;
    std::string email;
};

// Function to add a new account
void addNewAccount(std::list<Account>& accounts) {
    float inputBalance;
    std::string inputUsername;
    std::string inputPassword;
    std::string inputEmail;

    std::cout << "Set your balance: ";
    std::cin >> inputBalance;
    std::cout << "Set your username: ";
    std::cin >> inputUsername;
    std::cout << "Set your password: ";
    std::cin >> inputPassword;
    std::cout << "Set your email: ";
    std::cin >> inputEmail;

    Account acc;
    acc.setAccountDetails(inputBalance, inputUsername, inputPassword, inputEmail);
    accounts.push_back(acc);

    std::cout << "Account added successfully." << std::endl;
}

// Function to display account details
void showAccounts(const std::list<Account>& accounts) {
    if (accounts.empty()) {
        std::cout << "The list of accounts is empty." << std::endl;
    } else {
        std::cout << "Here are your account details: " << std::endl;
        for (Account account : accounts) {
            std::cout << account.getAccountDetails() << std::endl;
        }
    }
}

int main() {
    std::list<Account> accounts;

    while (true) {
        system("cls");
        std::cout << "How Can I Help you today?" << std::endl;
        std::cout << "[1] Add a new account" << std::endl;
        std::cout << "[2] Show accounts" << std::endl;
        std::cout << "[3] Quit" << std::endl;
        std::cout << "Choice: ";
        std::string input;
        std::cin >> input;

        if (input == "1") {
            addNewAccount(accounts);
        } else if (input == "2") {
            showAccounts(accounts);
        } else if (input == "3") {
            std::cout << "See you." << std::endl;
            break;
        } else {
            std::cout << "Invalid option." << std::endl;
        }

        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}
