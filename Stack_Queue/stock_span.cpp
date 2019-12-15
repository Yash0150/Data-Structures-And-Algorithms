#include <bits/stdc++.h> 
using namespace std; 

int span(int A[],int n){
	int A1[100]={0};

	stack<int>s;

	for(int day=0; day<n; day++){
		while(!s.empty() && A[s.top()]<A[day]){
			s.pop();
		}

		int betterday=(s.empty())? -1 : s.top();
		int span=day-betterday;
		A1[day]=span;
		s.push(day);
	}

	for(int i=0; i<n; i++){
		cout<<A1[i]<<" ";
	}
}

int main(){
	int n=6;
	//cin>>n;
	int A[n]={10, 4, 5, 90, 120, 80};
	/*for(int i=0; i<n; i++){
		cin>>A[i];
	}*/
	span(A,n);
}