#include<stdio.h>
#include<time.h>

unsigned long amount = 50000, deposit, withdraw, mobiletopup;
int choice, pin, k;
char transation = 'y';

int main() {
    // Pin validation
    while (pin != 9877) {
        printf("Enter Your Pin Number: ");
        scanf("%d", &pin);
        if (pin != 9877)
            printf("Please Enter Valid Pin\n");
    }

    do {
        // ATM Menu
        printf("********Welcome To ATM Service********\n");

        // Display current date and time
        time_t current_time = time(NULL);
        struct tm* tm = localtime(&current_time);
        printf("\nCurrent Date and Time:\n");
        printf("%s\n", asctime(tm));

        // Menu options
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Mobile Top Up\n");
        printf("5. Quit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYOUR BALANCE IN PKR: %lu\n", amount);
                break;
            case 2:
                printf("\nENTER THE AMOUNT TO WITHDRAW: PKR ");
                scanf("%lu", &withdraw);
                if (withdraw % 100 != 0) {
                    printf("\nPLEASE ENTER THE AMOUNT IN MULTIPLES OF 100\n");
                } else if (withdraw > (amount - 500)) {
                    printf("\nINSUFFICIENT BALANCE\n");
                } else {
                    amount = amount - withdraw;
                    printf("\nPlease Collect Your Cash\n");
                    printf("Your Current Balance is PKR: %lu\n", amount);
                }
                break;

            case 3:
                printf("\nENTER THE AMOUNT TO DEPOSIT: PKR ");
                scanf("%lu", &deposit);
                amount = amount + deposit;
                printf("\nYour Balance Is PKR: %lu\n", amount);
                break;

            case 4:
                printf("\nENTER THE AMOUNT FOR MOBILE TOP-UP: PKR ");
                scanf("%lu", &mobiletopup);
                amount = amount - mobiletopup;
                printf("\nYour Balance Is PKR : %lu\n", amount);
                break;

            case 5:
                printf("\nThank You for Using ATM Machine\n");
                break;

            default:
                printf("\nInvalid Choice\n");
        }

        // Ask if the user wants another transaction
        printf("\nDo You Wish to Have Another Transaction? (y/n): ");
        getchar();  // to consume newline character
        scanf("%c", &transation);

        if (transation == 'n' || transation == 'N') {
            k = 1;
        }

    } while (!k);

    printf("\nThank You for Using Our ATM Machine\n");
    return 0;
}
