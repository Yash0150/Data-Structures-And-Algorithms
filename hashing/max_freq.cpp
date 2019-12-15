#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int>m;
	int n,ans=0,b=0;
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		if(m.count(a)==1){
			m[a]++;
		}
		else{
			m.insert(make_pair(a,1));
		}
	}
	map<int,int>::iterator it;
	for(it=m.begin(); it!=m.end(); it++){
		int a=ans;
		ans=max(ans,it->second);
		if(a!=ans){
			b=it->first;
		}
	}
	cout<<b;
}