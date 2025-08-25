#include <stdio.h>
#include <stdlib.h>

/*
    ********  Challenge  *******

    Calculate the area and perimeter of a rectangle

*/

int main()
{
    int height = 0;
    int width = 0;

    printf("Enter the height of the rectangle: ");
    scanf("%d", &height);
    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);

    int perimeter = 2 * (height + width);
    int area = height * width;

    printf("Your rectangle has a perimeter of : %d and an area of : %d \n", perimeter, area);
}
