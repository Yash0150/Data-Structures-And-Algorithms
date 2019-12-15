#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A[1000]={0};


void reset(string p){
	A[0]=0;
	ll i=1,j=0;
	while(i<p.size()){
		if(p[i]==p[j]){
			A[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j != 0){
                j = A[j-1];
            }else{
                A[i] =0;
                i++;
            }
		}
	}
}

string kmp_algo(string s, string p, ll n, ll m){
	reset(p);
	ll i=0,j=0;
	while(i < n && j < m){
        if(s[i] == p[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j = A[j-1];
            }else{
                i++;
            }
        }
    }
    if(j == m){
        return "true";
    }
    return "false";
}


int main(){
	string s,p;
	//cin>>s>>p;
	s="abcxabcdabcdabcy";
	p="abcdabcyw";
	ll n=s.size();
	ll m=p.size();
	cout<<kmp_algo(s,p,n,m);
}