#include<bits/stdc++.h>
using namespace std;

int insertionsort(vector <int> &v, int n){
	for(int i=1; i<n; i++){
		int key=v[i];
		int j=i-1;
		while(v[j]>key && j>=0){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=key;
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
