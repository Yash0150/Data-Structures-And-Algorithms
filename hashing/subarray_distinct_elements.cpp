#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=0;
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<n; i++){
		unordered_map<int,int>m;
		int count=0;
		for(int j=i; j<n; j++){
			if(m.count(A[j])==0){
				m.insert(make_pair(A[j],1));
				count++;
			}
			else{
				break;
			}
		}
		ans+=(count)*(count+1)/2;
	}
	cout<<ans;
}