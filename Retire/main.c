#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int age;
    int retireAge;
    int yearsLeft;
    char currentYear[5];
    int retireYear;
    time_t rawCurrentTime;
    struct tm *currentTime;

    printf("What is your current age? ");
    scanf("%d", &age);

    printf("At what age would you like to retire? ");
    scanf("%d", &retireAge);

    yearsLeft = retireAge - age;

    time(&rawCurrentTime);
    currentTime = localtime(&rawCurrentTime);
    strftime(currentYear, 5, "%Y", currentTime);

    retireYear = yearsLeft + atoi(currentYear);

    printf("You have %d years left until you can retire.\n", yearsLeft);
    printf("It's %s, so you can retire in %d.\n", currentYear, retireYear);

    return 0;
}
