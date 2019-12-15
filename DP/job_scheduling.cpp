#include<bits/stdc++.h>
using namespace std;

void pairsort(int a[], int b[],int c[], int n) 
{ 
    pair<int, pair<int,int>> pairt[n]; 
    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second.first = b[i];
        pairt[i].second.second= c[i]; 
    } 
    sort(pairt, pairt + n);
    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second.first;
        c[i] = pairt[i].second.second; 
    } 
} 

int main(){
	int n=4;
	//cin>>n;
	int A[n]={1,2,3,6},B[n]={2,100,5,19},C[n]={50,200,20,100};
	for(int i=0; i<n; i++){
		//cin>>A[i];
	}
	for(int i=0; i<n; i++){
		//cin>>B[i];
	}
	for(int i=0; i<n; i++){
		//cin>>C[i];
	}
	//pairsort(A,B,C,n);
	for(int i=1; i<n; i++){
		int ans=C[i];
		for(int j=0; j<i; j++){
			if(A[i]>=B[j]){
				ans=max(ans,C[i]+C[j]);
			}
		}
		C[i]=ans;
	}
	int ans=0;
	for(int i=0; i<n; i++){
		ans=max(ans,C[i]);
	}
	cout<<ans;
}