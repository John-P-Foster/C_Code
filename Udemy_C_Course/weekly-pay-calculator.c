#include <stdio.h>

int main()
{
    int hours = 0;
    double basePay = 12.00;
    int regularHoursLimit = 40;
    double overTime = basePay * 1.5;
    int firstBracket = 300;
    int secondBracket = 150;
    int thirdBracket = firstBracket + secondBracket;
    double firstTaxRate = .15;
    double secondTaxRate = .20;
    double thirdTaxRate = .25;
    double tax = 0;
    double gross = 0;
    double net = 0;

    printf("Please enter in the number of hours worked this week: ");
    scanf("%d", &hours);

    if (hours > regularHoursLimit)
    {
        hours -= regularHoursLimit;
        gross += hours * overTime;
        hours = regularHoursLimit;
    }

    gross += hours * basePay;

    if (gross > (thirdBracket))
    {
        tax = firstBracket * firstTaxRate;
        tax += secondBracket * secondTaxRate;
        tax += ((gross - thirdBracket) * thirdTaxRate);
    }
    else if (gross <= thirdBracket && gross > firstBracket)
    {
        tax = firstBracket * firstTaxRate;
        tax += ((gross - firstBracket) * secondTaxRate);
    }
    else if (gross <= firstBracket)
    {
        tax = gross * firstTaxRate;
    }

    net = gross - tax;

    printf("Your Gross Pay: %.2f Taxes: %.2f Net Pay: %.2f", gross, tax, net);

    return 0;
}