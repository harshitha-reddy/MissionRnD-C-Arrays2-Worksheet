/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isLarger(char *dob1, char *dob2);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int totLen = ALen + BLen;
	struct transaction *result = (struct transaction *)malloc(totLen*sizeof(struct transaction));
	//struct transaction *temp = (struct transaction *)malloc(sizeof(totLen));
	//struct transaction *result;
	if ((A == NULL) || (B == NULL))
		return NULL;
	int i = 0, j = 0, k = 0;
	while ((i < ALen) && (j < BLen))
	{
		if (isLarger(A[i].date, B[j].date) == 1)
		{
			result[k] = A[i];
			i++;
		}
		else
		{
			result[k] = B[j];
			j++;
		}
		k++;
	}
	while (j < BLen){
		result[k] = B[j];
		j++;
		k++;
	}

	while (i < ALen){
		result[k] = A[i];
		i++;
		k++;
	}

	return result;
}
int isLarger(char *dob1, char *dob2) {
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
