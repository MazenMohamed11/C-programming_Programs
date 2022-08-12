#include<stdio.h>
#define ARRAY_SIZE 10
int flag = 0;

int search(int* array, int arraySize, int numberToSearch)
{
	int c,j,temp,start=0,end=(ARRAY_SIZE-1),mid,index=0;

 /* sorting the array using Bubble sort */
	for (c = 0; c < ARRAY_SIZE; c++)
	{
		for (j = 0; j < (ARRAY_SIZE - c); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			else
			{ }
		}

	}

	/* search for the number using binary search */
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (numberToSearch == array[mid])
		{
			flag = 1;
			index = mid;
			break;
		}
		else if (numberToSearch < array[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return index;
}

int main()
{
	int arr[ARRAY_SIZE], searchNumber, index, i;
	printf("Enter the Numbers you want \n");
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("Enter The Number to search :\n");
	scanf_s("%d", &searchNumber);
	index= search(arr, ARRAY_SIZE, searchNumber);
	switch (flag)
	{
	case 1:
		printf("The Number is Exist in index : %d ",index);
		break;
	case 0:
		printf("The Number does not Exist");
		break;
	}

}