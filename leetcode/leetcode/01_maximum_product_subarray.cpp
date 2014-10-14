/*
	https://oj.leetcode.com/problems/maximum-product-subarray/

	Maximum Product Subarray

	Find the contiguous subarray within an array (containing at least one number) which has the largest product.

	For example, given the array [2,3,-2,4],
	the contiguous subarray [2,3] has the largest product = 6.

	*/

#include "01_maximum_product_subarray.h"

int maxProduct(int A[], int n) {
	int max_so_far = A[0], max_until_here = A[0], min_until_here = A[0];

	for (int i = 1; i < n; i++)
	{
		if (A[i] > 0){
			if (max_until_here > 0)
				max_until_here *= A[i];
			else
				max_until_here = A[i];

			if (min_until_here > 0)
				min_until_here = A[i];
			else
				min_until_here *= A[i];
		}
		else if (A[i] == 0){
			max_until_here = 0;
			min_until_here = 0;
		}
		else { // A[i] < 0

			if (max_until_here > 0){
				int temp = max_until_here;
				if (min_until_here <= 0)
					max_until_here = min_until_here * A[i];
				else
					max_until_here = A[i];

				min_until_here = A[i] * temp;
			}
			else { // max_until_here <=0
				max_until_here = min_until_here * A[i];
				min_until_here = A[i];
			}
		}

		if (max_until_here > max_so_far){
			max_so_far = max_until_here;
		}
	}

	return max_so_far;
}

void maxProduct_Test(){
	int arr[3] = { 0, -2, -3 };
	int length = sizeof(arr) / sizeof(int);
	int product = maxProduct(arr, length);
}