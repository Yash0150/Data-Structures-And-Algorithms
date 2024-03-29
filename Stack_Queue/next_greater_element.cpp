// A Stack based C++ program to find next 
// greater element for all array elements 
// in same order as input. 
#include <bits/stdc++.h> 
using namespace std; 

/* prints element and NGE pair for all 
elements of arr[] of size n */
void printNGE(int arr[], int n) 
{ 
	stack<int> s; 

	int arr1[n]; 

	// iterating from n-1 to 0 
	for (int i = n - 1; i >= 0; i--) 
	{ 
		/*We will pop till we get the 
		greater element on top or stack gets empty*/
		while (!s.empty() && s.top() < arr[i]) 
			s.pop(); 

		/*if stack gots empty means there 
		is no element on right which is greater 
		than the current element. 
		if not empty then the next greater 
		element is on top of stack*/
		if (s.empty()) 
			arr1[i] = -1;		 
		else
			arr1[i] = s.top();		 

		s.push(arr[i]); 
	} 

	for (int i = 0; i < n; i++) 
		cout << arr[i] << " ---> " << arr1[i] << endl; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 11, 13, 21, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printNGE(arr, n); 
	return 0; 
} 
