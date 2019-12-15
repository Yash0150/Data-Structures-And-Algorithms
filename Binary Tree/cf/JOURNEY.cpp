#include<bits/stdc++.h>
using namespace std;
#define ll long long

void cal(std::vector<std::vector<ll>> v,unordered_map<ll,ll> &m,ll i,ll distance[],ll visited[]){
	visited[i]=1;
	if(m.count(i)){
		m[i]=distance[i];
	}

	for(auto neighbour: v[i]){
		if(visited[neighbour]!=1){
			distance[neighbour]=1+distance[i];
			cal(v,m,neighbour,distance,visited);
		}
	}
	return;
}

int main(){
	
	ll n,a,b;
	
	cin>>n;
	std::vector<std::vector<ll>> v(n+1);
	ll visited[100002]={0};
	ll distance[100002]={0};
	for(ll i=0; i<n-1; i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	unordered_map<ll,ll> m;
	for(ll i=2; i<=n; i++){
		if(v[i].size()==1){
			m[i]=-1;
		}
	}
	distance[1]=0;
	visited[1]=1;
	cal(v,m,1,distance,visited);
	float s=0;
	for(auto i:m){
		s+=i.second;
	}
	s/=m.size();
	cout<<s;
}