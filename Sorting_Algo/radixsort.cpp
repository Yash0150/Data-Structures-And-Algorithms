#include<bits/stdc++.h>
using namespace std;

int maxnbr(vector <int> &v, int n){
	int max= v[0];
	for(int i=0; i<n; i++){
		if(v[i]>max){
			max=v[i];
		}
	}
	return max;
}

int countsort(vector <int> &v, int n, int exp){
	vector <int> o(n);
	vector <int> count(10,0);
	
	for(int i=0; i<n; i++){
		count[(v[i]/exp)%10]++;
	}
	
	for(int i=0; i<9; i++){
		count[i+1]+=count[i];
	}

	for(int i=n-1; i>=0; i--){
		o[count[(v[i]/exp)%10]-1]=v[i];
		count[(v[i]/exp)%10]--;
	}
	v=o;
	//for(int i=0; i<n; i++){
	//	v[i]=o[i];
	//}
}

int radixsort(vector <int> &v, int n){
	int m=maxnbr(v,n);
	
	for(int exp=1; (m/exp)>0; exp*=10){
		countsort(v,n,exp);
	}
}

int main(void){
	vector <int> v;
	for(int i=0; i<5; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	radixsort(v,5);
	for(int i=0; i<5; i++){
		cout<<v[i]<<" ";
	}
}

