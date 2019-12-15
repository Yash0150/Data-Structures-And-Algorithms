#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll cal(std::vector<ll> &A,ll x,ll p){
	if(x==1){
		return A[1];
	}
	if((x&1)){
		if(p==-1){
			A[x/2]=(A[x-1]^A[x]);
		}
		else{
			A[x/2]=(A[x]|A[x-1]);
		}
	}
	else{
		if(p==-1){
			A[x/2]=(A[x+1]^A[x]);
		}
		else{
			A[x/2]=(A[x]|A[x+1]);
		}
	}
	return cal(A,x/2,p*(-1));
}

int main(){
	ll n,q,a;
	cin>>n>>q;
	a=n;
	n=1<<n;
	ll m=(n<<1);
	std::vector<ll> A(m,0);
	for(ll i=m-1; i>m-n-1; i--){
		cin>>A[i];
	}
	ll p=1;
	for(ll i=a; i>0; i--){
		for(ll j=pow(2,i)-1; j>=pow(2,i-1); j--){
			if(p==-1){
				A[j]=(A[j*2]^A[(j*2)+1]);
			}
			else{
				A[j]=(A[j*2]|A[(j*2)+1]);
			}
		}
		p*=-1;
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		A[m-x]=y;
		cout<<cal(A,m-x,1)<<endl;
	}
}