#include <bits/stdc++.h> 
using namespace std; 

void area(ll A[],ll n){
	stack<ll>s;
	ll i=0;
	ll max_area=0;
	while(i<n){
		if(s.empty() || A[s.top()]<=A[i]){
			s.push(i++);
		}
		else{
			ll top=s.top();
			s.pop();

			ll area_=A[top]*((s.empty())?i:(i-s.top()-1));
			max_area=max(area_,max_area);
		}
	}
	while(!s.empty()){
		ll top=s.top();
		s.pop();

		ll area_=A[top]*((s.empty())?i:(i-s.top()-1));
		max_area=max(area_,max_area);
	}
	cout<<max_area;
}

int main(){
	ll n;
	cin>>n;
	ll A[n];
	for(ll i=0;i<n; i++){
		cin>>A[i];
	}
	area(A,n);
}