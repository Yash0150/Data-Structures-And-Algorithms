#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	priority_queue<int> pq_max;
	priority_queue<int, vector<int>, greater<int>> pq_min;

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll A[n];
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		ll l1=1,l2=0;
		pq_max.push(A[0]);
		cout<<A[0]<<" ";
		ll median=A[0];
		for(int i=1; i<n; i++){
			if(A[i]>=median){
				pq_min.push(A[i]);
				l2++;
			}
			else{
				pq_max.push(A[i]);
				l1++;
			}
			if(l1>l2 && l1-l2>=2){
				int a=pq_max.top();
				pq_max.pop();
				pq_min.push(a);
				l1--;
				l2++;
			}
			else if(l1<l2 && l2-l1>=2){
				int a=pq_min.top();
				pq_min.pop();
				pq_max.push(a);
				l2--;
				l1++;
			}
			if((l1+l2)%2==0){
				median=(pq_max.top() + pq_min.top())/2;
			}
			else{
				if(l1>l2){
					median=pq_max.top();
				}
				else{
					median=pq_min.top();
				}
			}
			cout<<median<<" ";
		}
	}
}