#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,anss=0;
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<n; i++){
	    int ans=0;
		unordered_map<int,int>m;
		for(int j=i; j<n; j++){
			if(m.count(A[j])==0){
				m.insert(make_pair(A[j],1));
				int mm=ans;
				mm=(mm)^(A[j]);
				ans=max(ans,mm);
			}
			else{
				break;
			}
		}
		anss=max(ans,anss);
	}
	cout<<anss;
}