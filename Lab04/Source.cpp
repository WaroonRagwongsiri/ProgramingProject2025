#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MIN_BALANCE 100
#define WITHDRAW_FEE 10
#define TRANSFER_FEE 15
#define MIN_DEPOSIT 500
#define MAX_TRANSACTION 100000
#define INTEREST_RATE 0.02
#define INTEREST_THRESHOLD 10000

typedef struct {
	int accountNumber;
	char ownerName[50];
	float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
int findAccount(int accountNumber);
void createAccount();
void deposit();
void withdraw();
void transfer();
void checkBalance();
void calculateInterest();

int main() {
	int choice;

	do {
		printf("\n=== Banking System ===\n");
		printf("1. Create Account\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("4. Transfer\n");
		printf("5. Check Balance\n");
		printf("6. Calculate Interest\n");
		printf("0. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: createAccount(); break;
		case 2: deposit(); break;
		case 3: withdraw(); break;
		case 4: transfer(); break;
		case 5: checkBalance(); break;
		case 6: calculateInterest(); break;
		case 0: printf("Thank you for using Banking System\n"); break;
		default: printf("Invalid choice\n");
		}
	} while (choice != 0);

	return 0;
}

int findAccount(int accountNumber) {
	for (int i = 0; i < accountCount; i++) {
		if (accounts[i].accountNumber == accountNumber) {
			return i;
		}
	}
	return -1;
}

void createAccount() {
	if (accountCount >= MAX_ACCOUNTS) {
		printf("Maximum accounts reached\n");
		return;
	}

	int accountNumber;
	char name[50];
	float initialDeposit;

	printf("Enter account number (6 digits): ");
	scanf("%d", &accountNumber);


	if (accountNumber < 100000 && accountNumber > 999999) {
		printf("Error: Account number must be 6 digits\n");
		return;
	}

	if (findAccount(accountNumber) != -1) {
		printf("Error: Account number already exists\n");
		return;
	}

	printf("Enter owner name: ");
	scanf(" %[^\n]", name);

	if (strlen(name) == 0) {
		printf("Error: Name cannot be empty\n");
		return;
	}

	printf("Enter initial deposit: ");
	scanf("%f", &initialDeposit);

	if (initialDeposit < MIN_DEPOSIT) {
		printf("Error: Minimum initial deposit is %.2f\n", (float)MIN_DEPOSIT);
		return;
	}

	accounts[accountCount].accountNumber = accountNumber;
	strcpy(accounts[accountCount].ownerName, name);
	accounts[accountCount].balance = initialDeposit;
	accountCount++;

	printf("Account created successfully\n");
	printf("Account: %d, Owner: %s, Balance: %.2f\n",
		accountNumber, name, initialDeposit);
}

void deposit() {
	int accountNumber;
	float amount;

	printf("Enter account number: ");
	scanf("%d", &accountNumber);

	int index = findAccount(accountNumber);
	if (index == -1) {
		printf("Error: Account not found\n");
		return;
	}

	printf("Enter deposit amount: ");
	scanf("%f", &amount);


	if (amount <= 0 || amount >= MAX_TRANSACTION) {
		printf("Error: Invalid deposit amount\n");
		return;
	}

	accounts[index].balance += amount;
	printf("Deposit successful. New balance: %.2f\n", accounts[index].balance);
}

void withdraw() {
	int accountNumber;
	float amount;

	printf("Enter account number: ");
	scanf("%d", &accountNumber);

	int index = findAccount(accountNumber);
	if (index == -1) {
		printf("Error: Account not found\n");
		return;
	}

	printf("Enter withdrawal amount: ");
	scanf("%f", &amount);

	if (amount <= 0) {
		printf("Error: Invalid withdrawal amount\n");
		return;
	}


	float totalDeduction = amount + WITHDRAW_FEE;
	if (accounts[index].balance - amount < MIN_BALANCE) {
		printf("Error: Insufficient balance (minimum balance: %d after fees)\n", MIN_BALANCE);
		return;
	}

	accounts[index].balance -= totalDeduction;
	printf("Withdrawal successful. Fee: %d, New balance: %.2f\n",
		WITHDRAW_FEE, accounts[index].balance);
}

void transfer() {
	int fromAccount, toAccount;
	float amount;

	printf("Enter source account: ");
	scanf("%d", &fromAccount);

	printf("Enter destination account: ");
	scanf("%d", &toAccount);

	if (fromAccount == toAccount) {
		printf("Error: Cannot transfer to same account\n");
		return;
	}

	int fromIndex = findAccount(fromAccount);
	int toIndex = findAccount(toAccount);

	if (fromIndex == -1 || toIndex == -1) {
		printf("Error: One or both accounts not found\n");
		return;
	}

	printf("Enter transfer amount: ");
	scanf("%f", &amount);

	if (amount <= 0) {
		printf("Error: Invalid transfer amount\n");
		return;
	}

	float totalDeduction = amount + TRANSFER_FEE;
	if (accounts[fromIndex].balance - totalDeduction < MIN_BALANCE) {
		printf("Error: Insufficient balance for transfer\n");
		return;
	}

	accounts[fromIndex].balance -= totalDeduction;
	accounts[toIndex].balance += amount;

	printf("Transfer successful. Fee: %d\n", TRANSFER_FEE);
	printf("Source account balance: %.2f\n", accounts[fromIndex].balance);
	printf("Destination account balance: %.2f\n", accounts[toIndex].balance);
}

void checkBalance() {
	int accountNumber;

	printf("Enter account number: ");
	scanf("%d", &accountNumber);

	int index = findAccount(accountNumber);
	if (index == -1) {
		printf("Error: Account not found\n");
		return;
	}

	printf("Account: %d\n", accounts[index].accountNumber);
	printf("Owner: %s\n", accounts[index].ownerName);
	printf("Balance: %.2f\n", accounts[index].balance);
}

void calculateInterest() {
	int count = 0;

	printf("Calculating interest for eligible accounts...\n");

	for (int i = 0; i < accountCount; i++) {

		if (accounts[i].balance >= INTEREST_THRESHOLD) {
			float interest = accounts[i].balance * INTEREST_RATE;
			accounts[i].balance += interest;

			printf("Account %d: Interest %.2f, New balance: %.2f\n",
				accounts[i].accountNumber, interest, accounts[i].balance);
			count++;
		}
	}

	if (count == 0) {
		printf("No accounts eligible for interest\n");
	}
	else {
		printf("Interest calculated for %d accounts\n", count);
	}
}