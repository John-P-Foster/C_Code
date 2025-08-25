#include <stdio.h>
#include <stdlib.h>

int main()
{

    enum Company
    {
        GOOGLE,
        FACEBOOK,
        XEROX,
        YAHOO,
        EBAY,
        MICROSOFT
    };

    enum Company xerox = XEROX;
    enum Company google = GOOGLE;
    enum Company ebay = EBAY;

    printf("The value of xerox is: %d\n", xerox);
    printf("The value of google is: %d\n", google);
    printf("The value of ebay is: %d\n", ebay);

    // How to change the percsion of a float/
    float x = 3.4545466433355;
    printf("%.2f", x);

    return 0;
}