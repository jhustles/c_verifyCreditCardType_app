#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main(void)
{
    // Declare variables.
    long ccNumber;
    int sumOfProductDigits;
    int sumOfNonProductDigits; // sum of digits that are not products
    int checkSum;
    long num1, num2;

    // Prompt user for credit card input.
    do
    {
        ccNumber = get_long("Number: ");
        // printf("%li\n", ccNumber);
    }
    while (ccNumber < 0);


    sumOfProductDigits = 0;
    sumOfNonProductDigits = 0;

    long ccNumbers1 = ccNumber; // Used for checkSum
    long ccNumbers2 = ccNumber; // Used for card validation

    while (ccNumbers1 > 0)
    {
        num1 = ccNumbers1 % 10; // out: 4
        sumOfNonProductDigits += num1; // add 4
        // printf("Adding %li\n to sumOfNonProductDigits\n", num1);

        ccNumbers1 = ccNumbers1 - num1; // minus the last digit
        ccNumbers1 = ccNumbers1 / 10; // reduce by one last digit by dividing by 10
        // printf("Updated ccNumbers1 after is: %li\n", ccNumbers1);
        // printf("###########################\n");

        // Second Number to iterate thru
        num2 = ccNumbers1 % 10; // out: 1
        // printf("Here's num2: %li\n \n", num2);
        // printf("Sum Of Product Digits: %i\n \n", sumOfProductDigits);
        // printf("Sum Of Non-Product Digits: %i\n \n", sumOfNonProductDigits);

        ccNumbers1 = ccNumbers1 - num2;
        ccNumbers1 /= 10;

        if (num2 * 2 > 9) // if there's two digits you'll have to add each digit
        {
            // Product result is double digits. Repeat the same thing to split numbers
            // and reduce the ccNumbers1
            num2 = num2 * 2;
            int numSlice = num2 % 10; // split by getting the last digit
            sumOfProductDigits += numSlice;
            sumOfProductDigits += ((num2 - numSlice) / 10); // add to products sum
        }
        else
        {
            // multiply the digit by 2 and add to sumOfProductDigits
            num2 = num2 * 2;
            sumOfProductDigits += num2;
        }
    }

    checkSum = sumOfProductDigits + sumOfNonProductDigits;
    // printf("CHECK SUM: %i\n", checkSum);

    // Algorithm to check if card is valid:
    if (checkSum % 10 == 0)
    {
        bool amex, mastercard, visa;

        amex =
            (ccNumbers2 >= 340000000000000 && ccNumbers2 < 350000000000000) ||
            (ccNumbers2 >= 370000000000000 && ccNumbers2 < 380000000000000);

        mastercard =
            (ccNumbers2 >= 5100000000000000 && ccNumbers2 < 5600000000000000);

        visa =
            (ccNumbers2 >= 4000000000000 && ccNumbers2 < 5000000000000) ||
            (ccNumbers2 >= 4000000000000000 && ccNumbers2 < 5000000000000000);

        if (amex)
        {
            printf("AMEX\n");
        }
        else if (mastercard)
        {
            printf("MASTERCARD\n");
        }
        else if (visa)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


