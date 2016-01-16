/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	if (A==0)
	return -1;
	int ones = 0, twos = 0, i;
	int common_bit_mask;
	for (i = 0; i< len; i++)
	{
		twos = twos | (ones & A[i]);
		ones = ones ^ A[i];

		common_bit_mask = ~(ones & twos);
		ones &= common_bit_mask;
		twos &= common_bit_mask;
	}

	return ones;
}