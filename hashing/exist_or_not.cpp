#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		unordered_map<int,int>m;
		int n,q;
		cin>>n;
		for(int i=0; i<n; i++){
			int a;
			cin>>a;
			m.insert(make_pair(a,i));
		}
		cin>>q;
		for(int i=0; i<q; i++){
			int a; 
			cin>>a;
			if(m.count(a)==1){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
	}
}