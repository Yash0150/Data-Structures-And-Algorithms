#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans=0;
int fpair(int n){
	if(n<=2){
		return n;
	}
	int x=fpair(n-1);
	//int y=(n-1)*fpair(n-2);
	return x;
}

int main(){
	int n;
	cin>>n;
	cout<<fpair(n);
}