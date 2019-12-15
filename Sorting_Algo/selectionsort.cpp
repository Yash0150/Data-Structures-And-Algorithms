#include<bits/stdc++.h>
using namespace std;

int swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int insertionsort(vector <int> &v1, int n){
	for(int i=0; i<n-1; i++){
		int min_indx=i;
		for(int j=i; j<n; j++){
			if(v1[j]<v1[min_indx]){
				min_indx=j;
			}
		}
		swap(&v1[i],&v1[min_indx]);
	}
}

int main(void){
	vector <int> v;
	for(int i=0; i<5; i++){
		int a;
		cin>>a;	
		v.push_back(a);
	}
	insertionsort(v, 5);
	for(int i=0; i<5; i++){
		cout<<v[i]<<" ";
	}
}
