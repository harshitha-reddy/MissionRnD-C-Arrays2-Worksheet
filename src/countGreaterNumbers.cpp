/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isOlder(char *dob1, char *dob2);
int isPresent(struct transaction *Arr, int len, char *date);
int isPresent(struct transaction *Arr, int len, char *date){
	int i, presentCount = 0, notPresentCount = 0, temp;
	for (i = 0; i <= len; i++){
		temp = isOlder(Arr[i].date, date);
		if (temp == 0){
			presentCount++;
		}
		if (Arr[i].date != date) {
			notPresentCount++;
		}
	}
	if (presentCount == len)
		return 1;
	if (notPresentCount == len)
		return 0;
	return -1;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, count = 0, temp, flag = 0;
	int isPresentValue = isPresent(Arr, len, date);
	if (isPresentValue == 1){
		return 0;
	}
	if (isPresentValue == 0){
		return 0;
	}
	for (i = 0; i <= len; i++)
	{

		temp = isOlder(Arr[i].date, date);
		if (temp == 1){
			count = count + 1;
		}
		if (temp == 0){
			flag += 1;
			if (flag >= 2){
				return 0;
			}
			else
				return (len - (i + 1));
		}
	}
	return 0;
}
int isOlder(char *dob1, char *dob2) {
	int date1 = 0, date2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0, flag = 0, iterator, leap = 0;
	int valid = 0;

	for (iterator = 0; dob1[iterator] != '\0'; iterator++)
	{
		if (dob1[iterator] == '-')
		{
			flag++;
			continue;
		}
		if (flag == 0)
		{
			date1 = date1 * 10 + (dob1[iterator] - '0');
			date2 = date2 * 10 + (dob2[iterator] - '0');
		}
		if (flag == 1)
		{
			month1 = month1 * 10 + (dob1[iterator] - '0');
			month2 = month2 * 10 + (dob2[iterator] - '0');
		}
		if (flag == 2)
		{
			year1 = year1 * 10 + (dob1[iterator] - '0');
			year2 = year2 * 10 + (dob2[iterator] - '0');
		}

	}
	if (date2 == 0)
		return -1;
	if ((year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0)))
	{
		leap = 1;
	}
	if (leap != 1)
	{
		if ((month1 == 2) || (month2 == 2))
		{
			if ((date1 >= 29) || (date2 >= 29))
				return -1;
		}
	}
	if (month1<13 && month2<13)
	{
		if ((month1 == 1 || (3 || (5 || (7 || (8 || (10 || (12))))))) && (month2 == 1 || (3 || (5 || (7 || (8 || (10 || (12))))))))
		{
			if (date1 <= 31 || date2 <= 31)
			{
				valid = 1;
			}
		}
		else if ((month1 == 4 || (6 || (9 || (11)))) && (month2 == 4 || (6 || (9 || (11)))))
		{
			if ((date1 <= 30) || (date2 <= 30))
			{
				valid = 1;
			}
		}
		else
		{
			if (leap == 1)
			{
				if ((date1 <= 29) || (date2 <= 29))
				{
					valid = 1;
				}
			}
			if (leap == 0)
			{
				if ((date1 <= 28) || (date2 <= 28))
				{
					valid = 1;
				}
			}
		}
	}
	if (valid != 1)
		return -1;
	else
	{
		if (year1>year2)
			return 2;
		else if (year1<year2)
			return 1;
		else
		{
			if (month1>month2)
				return 2;
			else if (month1<month2)
				return 1;
			else
			{
				if (date1>date2)
					return 2;
				else if (date1<date2)
					return 1;
				else
					return 0;
			}

		}

	}
}

