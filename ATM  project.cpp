/*
=======================================================
        ATM SIMULATION PROGRAM
        Course  : Programming Fundamentals (CC-112)
        Language: C  --  Runs perfectly in DevC++
=======================================================

HEADER FILES USED:
-------------------
1. <stdio.h>
   --> printf() aur scanf() isi se aate hain
   --> Har C program mein yeh ZAROORI hai

2. <stdlib.h>
   --> system("cls") isi se aata hai
   --> Screen saaf karne ke liye use hota hai

=======================================================
*/

#include <stdio.h>     /* printf() aur scanf() */
#include <stdlib.h>    /* system("cls")         */


int main()
{
    /* =================================================
       VARIABLES
       --> Sab kuch yahan declare karo - main ke andar
       ================================================= */

    int   correctPIN  = 1234;     /* ATM ka sahi PIN      */
    float balance     = 50000.0;  /* Account ka balance   */
    int   enteredPIN;             /* User jo PIN daale    */
    int   pinAttempts = 0;        /* Kitni baar daala     */
    int   maxAttempts = 3;        /* Max 3 chances        */
    int   loggedIn    = 0;        /* 0=bahar  1=andar     */
    int   choice;                 /* Menu option          */
    float amount;                 /* Deposit/withdraw amount */
    int   oldPIN, newPIN, confirmPIN;  /* PIN change ke liye */
    int   dummy;                  /* Pause ke liye        */


    /* =================================================
       STEP 1: PIN VERIFICATION
       --> while loop: 3 chances milenge
       ================================================= */

    system("cls");
    printf("  ================================================\n");
    printf("  ||                                            ||\n");
    printf("  ||      WELCOME TO HBL - Habib Bank ATM      ||\n");
    printf("  ||               24/7 Service                ||\n");
    printf("  ||                                            ||\n");
    printf("  ================================================\n");
    printf("\n");
    printf("  Please enter your PIN to continue.\n");
    printf("\n");

    while (pinAttempts < maxAttempts)    /* 3 se kam attempts? */
    {
        printf("  Enter PIN: ");
        scanf("%d", &enteredPIN);
        printf("\n");

        if (enteredPIN == correctPIN)    /* PIN sahi hai? */
        {
            loggedIn = 1;                /* Login successful */
            printf("  ================================================\n");
            printf("  ||      Login Successful! Welcome :)          ||\n");
            printf("  ================================================\n");
            printf("\n");
            break;                       /* Loop se bahar aao */
        }
        else                             /* PIN galat hai */
        {
            pinAttempts++;               /* Ek attempt count karo */
            printf("  !! Wrong PIN !!\n");
            printf("  Attempts left  :  %d\n", maxAttempts - pinAttempts);
            printf("\n");
        }
    }

    /* 3 baar galat PIN - account block */
    if (loggedIn == 0)
    {
        system("cls");
        printf("  ================================================\n");
        printf("  ||   ACCOUNT BLOCKED! Too many wrong        ||\n");
        printf("  ||   attempts. Contact your bank.           ||\n");
        printf("  ================================================\n");
        printf("\n");
        return 0;    /* Program band karo */
    }


    /* =================================================
       STEP 2: MAIN MENU LOOP
       --> while(1): jab tak choice 5 na ho
       ================================================= */

    while (1)
    {
        /* ---- Menu dikhao ---- */
        system("cls");
        printf("  ================================================\n");
        printf("  ||                                            ||\n");
        printf("  ||      WELCOME TO HBL - Habib Bank ATM      ||\n");
        printf("  ||               24/7 Service                ||\n");
        printf("  ||                                            ||\n");
        printf("  ================================================\n");
        printf("\n");
        printf("  Account Holder  :  Habib UR Rehman \n");
        printf("  Account Number  :  PK-****-****-7890\n");
        printf("\n");
        printf("  ================================================\n");
        printf("  ||              MAIN MENU                    ||\n");
        printf("  ================================================\n");
        printf("  ||                                            ||\n");
        printf("  ||     1.  Check Balance                     ||\n");
        printf("  ||     2.  Deposit Money                     ||\n");
        printf("  ||     3.  Withdraw Money                    ||\n");
        printf("  ||     4.  Change PIN                        ||\n");
        printf("  ||     5.  Exit / Logout                     ||\n");
        printf("  ||                                            ||\n");
        printf("  ================================================\n");
        printf("\n");
        printf("  Enter your choice (1-5): ");
        scanf("%d", &choice);
        printf("\n");


        /* ---- Option 1: Balance Check ---- */
        if (choice == 1)
        {
            printf("  ================================================\n");
            printf("  ||             ACCOUNT BALANCE               ||\n");
            printf("  ================================================\n");
            printf("\n");
            printf("  Your Current Balance  :  Rs. %.2f\n", balance);
            /* %.2f --> float 2 decimal places ke saath */
            printf("\n");
            printf("  ================================================\n");
            printf("\n");
            printf("  Enter any number + Enter to go back: ");
            scanf("%d", &dummy);
        }


        /* ---- Option 2: Deposit Money ---- */
        else if (choice == 2)
        {
            printf("  ================================================\n");
            printf("  ||              DEPOSIT MONEY                ||\n");
            printf("  ================================================\n");
            printf("\n");
            printf("  Current Balance  :  Rs. %.2f\n", balance);
            printf("\n");
            printf("  Enter amount to deposit: Rs. ");
            scanf("%f", &amount);
            printf("\n");

            if (amount <= 0)    /* Galat amount */
            {
                printf("  !! ERROR: Amount must be greater than 0 !!\n");
            }
            else                /* Sahi amount - add karo */
            {
                balance = balance + amount;    /* Balance update */
                printf("  ================================================\n");
                printf("  ||   SUCCESS: Rs. %.2f Deposited!         ||\n", amount);
                printf("  ================================================\n");
                printf("\n");
                printf("  New Balance  :  Rs. %.2f\n", balance);
            }

            printf("\n");
            printf("  Enter any number + Enter to go back: ");
            scanf("%d", &dummy);
        }


        /* ---- Option 3: Withdraw Money ---- */
        else if (choice == 3)
        {
            printf("  ================================================\n");
            printf("  ||             WITHDRAW MONEY                ||\n");
            printf("  ================================================\n");
            printf("\n");
            printf("  Current Balance  :  Rs. %.2f\n", balance);
            printf("\n");
            printf("  Enter amount to withdraw: Rs. ");
            scanf("%f", &amount);
            printf("\n");

            if (amount <= 0)                  /* Case 1: Galat amount */
            {
                printf("  !! ERROR: Amount must be greater than 0 !!\n");
            }
            else if (amount > balance)        /* Case 2: Balance se zyada */
            {
                printf("  !! ERROR: Insufficient Balance !!\n");
                printf("\n");
                printf("  You Entered  :  Rs. %.2f\n", amount);
                printf("  Available    :  Rs. %.2f\n", balance);
            }
            else                              /* Case 3: Sab theek */
            {
                balance = balance - amount;    /* Balance update */
                printf("  ================================================\n");
                printf("  ||   SUCCESS: Rs. %.2f Withdrawn!         ||\n", amount);
                printf("  ================================================\n");
                printf("\n");
                printf("  Remaining Balance  :  Rs. %.2f\n", balance);
                printf("\n");
                printf("  Please collect your cash.\n");
            }

            printf("\n");
            printf("  Enter any number + Enter to go back: ");
            scanf("%d", &dummy);
        }


        /* ---- Option 4: Change PIN ---- */
        else if (choice == 4)
        {
            printf("  ================================================\n");
            printf("  ||               CHANGE PIN                  ||\n");
            printf("  ================================================\n");
            printf("\n");

            printf("  Enter your current PIN   : ");
            scanf("%d", &oldPIN);
            printf("\n");

            if (oldPIN != correctPIN)         /* Purana PIN galat */
            {
                printf("  !! ERROR: Wrong current PIN !!\n");
            }
            else                              /* Purana PIN sahi */
            {
                printf("  Enter new PIN (4 digits) : ");
                scanf("%d", &newPIN);

                printf("  Confirm new PIN          : ");
                scanf("%d", &confirmPIN);
                printf("\n");

                if (newPIN == confirmPIN)     /* Dono match kiye */
                {
                    correctPIN = newPIN;       /* PIN update karo */
                    printf("  ================================================\n");
                    printf("  ||   SUCCESS: PIN Changed Successfully!      ||\n");
                    printf("  ================================================\n");
                }
                else                          /* Match nahi kiya */
                {
                    printf("  !! ERROR: PINs do not match. Try again !!\n");
                }
            }

            printf("\n");
            printf("  Enter any number + Enter to go back: ");
            scanf("%d", &dummy);
        }


        /* ---- Option 5: Exit / Logout ---- */
        else if (choice == 5)
        {
            printf("  ================================================\n");
            printf("  ||                                            ||\n");
            printf("  ||   Thank you for using HBL ATM!  Bye :)   ||\n");
            printf("  ||                                            ||\n");
            printf("  ================================================\n");
            printf("\n");
            break;    /* Loop se bahar aao - program khatam */
        }


        /* ---- Galat choice ---- */
        else
        {
            printf("  !! Invalid choice! Please enter 1 to 5 only.\n");
            printf("\n");
            printf("  Enter any number + Enter to go back: ");
            scanf("%d", &dummy);
        }

    } /* while loop yahan khatam */


    return 0;    /* Program successfully khatam */

} /* main() khatam */
