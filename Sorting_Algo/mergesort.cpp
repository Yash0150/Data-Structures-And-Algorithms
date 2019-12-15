#include<bits/stdc++.h>
using namespace std;

int merge(vector <int> &v, int l, int m, int h){
	int n1=m-l+1;
	int n2=h-m;
	int i=0;
	int j=0;
	int k=l;
	vector <int> l1;

	for(int b=0; b<n1; b++){
		l1.push_back(v[l+b]);
	}

	vector <int> r1;
	
	for(int b=0; b<n2; b++){
		r1.push_back(v[m+b+1]);
	}

	while(i<n1 && j<n2){
		if(l1[i]>r1[j]){
			v[k]=r1[j];
			j++;
		}
		else{
			v[k]=l1[i];
			i++;
		}
		k++;
	}
	while(i<n1){
		v[k]=l1[i];
		i++;
		k++;
	}
	while(j<n2){
		v[k]=r1[j];
		j++;
		k++;
	}
}

int mergesort(vector <int> &v, int l, int h){

	if(l<h){
		int m=l+((h-l)/2);

		mergesort(v,l,m);
		mergesort(v,m+1,h);

		merge(v,l,m,h);
	}
}

int main(void){
	vector <int> v={1,5,4,3,6};
	for(int i=0; i<5; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	mergesort(v,0,4);
	for(int i=0; i<5; i++){
		cout<<v[i]<<" ";
	}
}
