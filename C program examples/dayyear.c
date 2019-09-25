 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
void calendar(int year, int daycode);
 int fm(int date, int month, int year)
{
	int fmonth, leap; //leap function 1 for leap & 0 for non-leap
  if ((year % 100 == 0) && (year % 400 != 0))
       leap = 0;
   else if (year % 4 == 0)
          leap = 1;
	  else
		 leap = 0;
  fmonth = 3 + (2 - leap) * ((month + 2) / (2 * month))+ (5 * month + month / 9) / 2; //bring it in range of 0 to 6
  fmonth = fmonth % 7;
  return fmonth;
}
int day_of_week(int date, int month, int year)
 {
   int dayOfWeek;
   int YY = year % 100;
   int century = year / 100;
printf("\nDate: %d/%d/%d \n", date, month, year);
dayOfWeek = 1.25 * YY + fm(date, month, year) + date - 2 * (century % 4); //remainder on division by 7
dayOfWeek = dayOfWeek % 7;
switch (dayOfWeek)
 {
  case 0:printf("weekday = Saturday");
		 break;
  case 1:printf("weekday = Sunday");
         break;
  case 2:printf("weekday = Monday");
		 break;
  case 3:printf("weekday = Tuesday");
         break;
  case 4:printf("weekday = Wednesday");
         break;
  case 5:printf("weekday = Thursday");
         break;
  case 6:printf("weekday = Friday");
         break;
 default:printf("Incorrect data");
 }
return 0;
}
int main()
{
  int date, month, year,ch;
printf("\n enter 0 to print total days in a year or enter 1 to print day of year");
scanf("%d",&ch);
if(ch==1)
{
	printf("\nEnter the year ");
    scanf("%d", &year);
    printf("\nEnter the month ");
    scanf("%d", &month);
    printf("\nEnter the date ");
    scanf("%d", &date);
   day_of_week(date, month, year);
   return 0;
}
else
{
  int year, daycode, leapyear;
	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");
}
}
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};
int inputyear(void)
{
	int year;
	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	 return year;
}
int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	 return daycode;
}
int determineleapyear(int year)
{
	if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
	{
		days_in_month[2] = 29;
		return 1;
	}
	else
	{
		days_in_month[2] = 28;
		return 0;
	}
}
void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" ); // Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		} // Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day ); // Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		} // Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}
