#include <bits/stdc++.h> 
using namespace std; 

int main(){
	int n,cost=0;
	cin>>n;
	queue<int>q;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		q.push(a);
	}
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<n; i++){
		if(A[i]==q.front()){
			q.pop();
			cost++;
		}
		else{
			while(A[i]!=q.front()){
				int f= q.front();
				q.pop();
				q.push(f);
				cost++;
			}
			q.pop();
			cost++;
		}
	}
	cout<<cost;
}