#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold account details
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount(struct Account accounts[], int *count);
void depositMoney(struct Account accounts[], int count);
void withdrawMoney(struct Account accounts[], int count);
void checkBalance(struct Account accounts[], int count);

int main() {
    struct Account accounts[100]; // maximum 100 accounts
    int count = 0; // total number of accounts
    int choice;

    while (1) {
        printf("\n===== BANKING MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                depositMoney(accounts, count);
                break;
            case 3:
                withdrawMoney(accounts, count);
                break;
            case 4:
                checkBalance(accounts, count);
                break;
            case 5:
                printf("Thank you for using Banking Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new account
void createAccount(struct Account accounts[], int *count) {
    printf("\nEnter account number: ");
    scanf("%d", &accounts[*count].accountNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]", accounts[*count].name); // read string with spaces
    accounts[*count].balance = 0.0;
    printf("Account created successfully!\n");
    (*count)++;
}

// Function to deposit money
void depositMoney(struct Account accounts[], int count) {
    int accNo, i;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully! Current balance = %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney(struct Account accounts[], int count) {
    int accNo, i;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! Current balance = %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to check balance
void checkBalance(struct Account accounts[], int count) {
    int accNo, i;
    printf("\nEnter account number: ");
    scanf("%d", &accNo);

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}


