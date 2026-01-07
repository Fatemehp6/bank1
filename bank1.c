#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

    char firstName[30];
    char lastName[30];
    int balance = 0;
    int pin = 1234;
    int isActive = 0;

    int transactions[10];
    int transactionCount = 0;
    int inputPin, attempts = 0;
    int choice;
    int amount;

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &inputPin);

        if (inputPin == pin) {
            break;} 
		else {
            attempts++;
            printf("Wrong PIN!\n");}
	}
    
    if (attempts == 3) {
        printf("Too many wrong attempts. Program terminated.\n");
        return 0;}

    do {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Show Balance\n");
        printf("5. Transaction History\n");
        printf("6. Change PIN\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: 
            if (isActive) {
                printf("Account already exists.\n");
			} 
			else {
                printf("Enter First Name: ");
                scanf("%s", firstName);

                printf("Enter Last Name: ");
                scanf("%s", lastName);

                printf("Enter Initial Balance: ");
                scanf("%d", &balance);

                isActive = 1;
                transactionCount = 0;

                printf("Account created successfully.\n");
			}
            break;

        case 2: 
            if (!isActive) {
                printf("No active account.\n");
			} 
			else {
                printf("Enter deposit amount: ");
                scanf("%d", &amount);

                if (amount > 0) {
                    balance += amount;

                    if (transactionCount < 10) {
                        transactions[transactionCount++] = amount;} 
					else {
                        for (int i = 0; i < 9; i++)
                            transactions[i] = transactions[i + 1];
                        transactions[9] = amount;}
                        
                    printf("Deposit successful.\n");
				} 
				else {
                    printf("Invalid amount.\n");
                }
            }
            break;

        case 3: 
            if (!isActive) {
                printf("No active account.\n");
			} 
			else {
                printf("Enter withdraw amount: ");
                scanf("%d", &amount);

                if (amount > 0 && amount <= balance) {
                    balance -= amount;

                    if (transactionCount < 10) {
                        transactions[transactionCount++] = -amount;}
					else {
                        for (int i = 0; i < 9; i++)
                            transactions[i] = transactions[i + 1];
                        transactions[9] = -amount;}

                    printf("Withdraw successful.\n");
                }
				else {
                    printf("Invalid or insufficient balance.\n");
                }
            }
            break;

        case 4: 
            if (!isActive) {
                printf("No active account.\n");
            }
			else {
                printf("Current Balance: %d\n", balance);
            }
            break;

        case 5: 
            if (!isActive) {
                printf("No active account.\n");
            }
			else if (transactionCount == 0) {
                printf("No transactions.\n");
            }
			else {
                printf("Last Transactions:\n");
                for (int i = 0; i < transactionCount; i++) {
                    if (transactions[i] > 0)
                        printf("Deposit: %d\n", transactions[i]);
                    else
                        printf("Withdraw: %d\n", -transactions[i]);
                }
            }
            break;

        case 6: 
            printf("Enter current PIN: ");
            scanf("%d", &inputPin);

            if (inputPin == pin) {
                printf("Enter new PIN: ");
                scanf("%d", &pin);
                printf("PIN changed successfully.\n");
            }
			else {
                printf("Wrong PIN.\n");
            }
            break;

        case 7: 
            if (!isActive) {
                printf("No account to delete.\n");
            }
			else {
                isActive = 0;
                balance = 0;
                transactionCount = 0;
                printf("Account deleted successfully.\n");
            }
            break;

        case 8:
            printf("Safe Exit. Goodbye!\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
