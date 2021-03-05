#include <stdio.h>
#include <stdlib.h>

#define CONVERSION_FACTOR 0.09290304

int main()
{
    printf("What is the length of the room in feet? ");
    int roomLengthFeet;
    scanf("%d", &roomLengthFeet);

    printf("What is the width of the room in feet? ");
    int roomWidthFeet;
    scanf("%d", &roomWidthFeet);

    printf("You entered dimensions of %d feet by %d feet.\n", roomLengthFeet, roomWidthFeet);

    long roomSquareFeet = roomLengthFeet * roomWidthFeet;
    printf("The area is\n");
    printf("%ld square feet\n", roomSquareFeet);

    double roomSquareMeters = roomSquareFeet * CONVERSION_FACTOR;
    printf("%f square meters\n", roomSquareMeters);

    return 0;
}
