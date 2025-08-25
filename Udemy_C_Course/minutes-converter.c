#include <stdio.h>
#include <stdlib.h>

int main()
{

    int userMinutes = 0;
    int convertHours = 0;
    int convertDays = 0;
    int convertYears = 0;

    const int minsInHour = 60;
    const int hoursInDay = 24;
    const int daysInYear = 365;

    const int minsInDay = minsInHour * hoursInDay;
    const int minsInYear = minsInDay * daysInYear;

    printf("Please enter in the number of minutes to convert to days, hours, and years: ");
    scanf("%d", &userMinutes);

    convertYears = userMinutes / minsInYear;
    userMinutes %= minsInYear;

    convertDays = userMinutes / minsInDay;
    userMinutes %= minsInDay;

    convertHours = userMinutes / minsInHour;
    userMinutes %= minsInHour;

    printf("Converted time: %d Years %d Days %d Hours %d Minutes", convertYears, convertDays, convertHours, userMinutes);

    return 0;
}