#include<bits/stdc++.h>
using namespace std;

int swap(int *x, int *y){
	int temp=*x;	
	*x=*y;
	*y=temp;
}


int bubblesort( vector <int> &v1, int n){
	for(int i=0; i<4; i++){
		for(int j=0; j<4-i; j++){
			if(v1[j+1]<v1[j]){
				swap(v1[j], v1[j+1]);
			}
		}
	}
}

int main(void){
	vector <int> v;
	for(int i=0; i<5; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	int m= v.size();
	bubblesort(v,m);
        for(int i=0; i<5; i++){
		cout<< v[i]<<" ";
	}
}
	
