#include<stdio.h>
#define TRUE 1
#define FALSE 0
int day_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = 
{
    " ",
    "\n\n\nJANUARY",
    "\n\n\nFEBRUARY",
    "\n\n\nMARCH",
    "\n\n\nAPRIL",
    "\n\n\nMAY",
    "\n\n\nJUN",
    "\n\n\nJULY",
    "\n\n\nAUGUST",
    "\n\n\nSEPTEMBER",
    "\n\n\nOCTOBER",
    "\n\n\nNOVEMBER",
    "\n\n\nDECEMBER",
};
int inputYear(void);
int LeapYear(int);
int DayCode(int);
void calender(int, int);


int main()
{
    int year, daycode, leapyear;
    year = inputYear();
    daycode = DayCode(year);
    leapyear = LeapYear(year);
    calender(year, leapyear);
    printf("\n");
    return 0;
}

int inputYear(void)
{
    int year;
    printf("ENTER YEAR (Y/Y/Y/Y): ");
    scanf("%d", &year);
    return year;
}
int LeapYear(int year)
{
    if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
    {
        day_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        day_in_month[2] = 28;
        return TRUE;
    }    
}
int DayCode(int year)
{
    int daycode;
    int d1, d2, d3;
    d1 = (year - 1)/4;
    d2 = (year - 1)/100;
    d3 = (year - 1)/400;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}
void calender(int year, int daycode)
{
    int month, day;
    for (month = 1; month <= 12; month++)
    {
        printf("%s", months[month]);
        printf("\n\nSUN  MON  TUE  WED  THUR  FRI  SAT\n");
        for (day = 1; day <= 1 + daycode * 5; day++)
        {
            printf(" ");
        }
        for (day = 1; day <= day_in_month[month]; day++)
        {
            printf("%3d", day);
            if ((day + daycode) % 7 > 0)
            {
                printf("  ");
            }
            else
            {
                printf("\n ");
            }
        }
        daycode = (daycode + day_in_month[month]) % 7;
    }   
}