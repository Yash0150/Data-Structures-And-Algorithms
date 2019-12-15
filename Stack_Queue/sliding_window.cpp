#include <bits/stdc++.h> 
using namespace std; 

int main(){
	int n,k;
	cin>>n>>k;
	deque<int>dq;
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<k; i++){
		while(!dq.empty() && dq.back()<A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout<<A[dq.front()]<<endl;
	for(int i=k; i<n; i++){
		while(!dq.empty() && dq.front()<=i-k){
			dq.pop_front();
		}
		while(!dq.empty() && A[dq.back()]<A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		cout<<A[dq.front()]<<endl;
	}
}