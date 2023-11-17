// 이진 탐색
#include <stdio.h>

int BinarySearch(int*, int, int);
int main(void) {
	int arr[] = { 1,2,3,5,9,12,25,31,45 };
	int idx;

	idx = BinarySearch(arr, sizeof(arr) / sizeof(int), 3);
	if (idx == -1)
		printf("검색할 대상없음\n");
	else
		printf("검색한 인덱스 : %d \n", idx);
	return 0;
}

int BinarySearch(int ar[], int len, int target)
{
	int first = 0; 
	int last = len - 1; 
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == ar[mid]) 
			return mid; 
		else 
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1; 
}