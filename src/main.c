#include <stdio.h>

void printSeparator() {
    printf("\n=================================\n");
}

void displayMenu() {
    printSeparator();
    printf("      Banking System");
    printSeparator();
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit");
    printSeparator();
    printf("Choose an option: ");
}

void displayBalance(float balance) {
    printSeparator();
    printf("Current Balance\n");
    printf("Your current balance is: $%.2f", balance);
}

void displayDeposit(float amount, float balance) {
    printSeparator();
    printf("Deposit Money\n");
    printf("Successfully deposited $%.2f.\nNew balance: $%.2f", amount, balance);
}

void displayWithdraw(float amount, float balance) {
    printSeparator();
    printf("Withdraw Money");
    printSeparator();
    printf("Successfully withdrew $%.2f\nNew balance: $%.2f", amount, balance);
}

int main() {
    float balance = 0.0;
    int choice;
    float amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBalance(balance);
                break;

            case 2:
                printf("Enter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    displayDeposit(amount, balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    displayWithdraw(amount, balance);
                }
                
                else if (amount > balance) {
                    printf("Insufficient funds. Your current balance is: $%.2f\n", balance);
                }
                
                else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;

            case 4:
                printf("\nExiting the banking system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}