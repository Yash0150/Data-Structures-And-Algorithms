#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sieve(vector<ll> &v){
	vector<bool>prime(1000000,true);
	prime[0]=false;
	prime[1]=false;
	v.push_back(0);
	for(ll i=2; i<1000000; i++){
		if(prime[i]==true){
			for(ll j=i*2; j<1000000; j+=i){
				prime[j]=false;
			}
			v.push_back(i);
		}
	}
}

int main(){
	vector<ll> v;
	stack<ll> s,s1;
	sieve(v);
	ll n,q;
	cin>>n>>q;
	for(ll i=0; i<n; i++){
		ll a;
		cin>>a;
		s.push(a);
	}
	for(ll i=1; i<=q; i++){
		ll m=s.size();
		for(ll j=0; j<m; j++){
			s1.push(s.top());
			s.pop();
		}
		swap(s,s1);
		for(ll j=0; j<m; j++){
			if((s.top()%v[i])==0){
				cout<<s.top()<<" ";
				s.pop();
			}
			else{
				s1.push(s.top());
				s.pop();
			}
		}
		swap(s,s1);
	}
	ll m=s.size();
	for(ll i=0; i<m; i++){
			s1.push(s.top());
			s.pop();
		}
		swap(s,s1);
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}

}