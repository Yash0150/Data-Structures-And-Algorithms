#include<bits/stdc++.h>
using namespace std;

bool A[1000001][1000001];

bool match(string s, string p, int n, int m){
	memset(A,false,sizeof(A));
	A[0][0]=true;
	for(int i=1; i<=m; i++){
		if(p[i-1]=='*'){
			A[0][i]=A[0][i-1];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1;j<=m; j++){
			if(p[j-1]=='*'){
				A[i][j]=A[i-1][j] || A[i][j-1];
			}
			else if(p[j-1]=='?' || s[i-1]==p[j-1]){
				A[i][j]=A[i-1][j-1];
			}
			else{
				A[i][j]=false;
			}
		}
	}
}

int main(){
	string s,p;
	cin>>s>>p;
	int n=s.size();
	int m=p.size();
	match(s,p,n,m);
	for(int i=0; i<n+1; i++){
		for(int j=0; j<m+1; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cou
}