#include<bits/stdc++.h>
using namespace std;
//#define int long long

/*int maxDivide(int a,int b) 
{ 
  while (a%b == 0) 
   a = a/b;  
  return a; 
}   

int isUgly(int no){
	no = maxDivide(no, 2); 
  no = maxDivide(no, 3); 
  no = maxDivide(no, 5); 
    
  return (no == 1)? 1 : 0;      
}

int getNthUglyNo(int n) 
{ 
  int i = 1;  
  int count = 1;    
  while (n > count) 
  { 
    i++;       
    if (isUgly(i)) 
      count++;  
  } 
  return i; 
}*/
long long dp[100001];

long long getnumm(long long n){
	dp[0]=1;
	int i=1;
	int n2=0;
	int n3=0;
	int n5=0;
	long long x=2;
	long long y=3;
	long long z=5;
	while(i!=n){
		long long a=2*dp[n2];
		long long b=3*dp[n3];
		long long c=5*dp[n5];
		dp[i]=min(a,min(b,c));
		if(dp[i]==a){
			n2++;
		}
		if(dp[i]==b){
			n3++;
		}
		if(dp[i]==c){
			n5++;
		}
		i++;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		getnumm(n);
		cout<<dp[n-1]<<endl; 
	}
}
