#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll length(std::map<ll, list<ll>> v,ll src){
	queue<ll> q;
	map<ll,bool> visited;
	map<ll,ll> distance;
	map<ll,ll> parent;

	

	q.push(src);
	visited[src]=true;
	distance[src]=0;
	parent[src]=src;

	while(!q.empty()){

		ll node = q.front();
		//cout<<node<<" ";
		q.pop();

		for(auto neighbour:v[node]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour]=true;
				distance[neighbour]=distance[node]+1;
				parent[neighbour]=node;
			}
		}
	}
	ll bst=0;
	for(auto i:distance){
		bst=max(bst,i.second);
	}
	return bst+1;
}

int main(){
	ll n,a;
	cin>>n;
	std::map<ll, list<ll>> v;
	std::vector<ll> A;
	for(ll i=1; i<=n; i++){
		cin>>a;
		if(a!=-1){
			v[a].push_back(i);
		}
		else{
			A.push_back(i);
		}
	}
	std::vector<ll> root;
	for(ll i=0; i<A.size(); i++){
		if(v.count(A[i])){
			root.push_back(A[i]);
		}
	}
	ll bst=0;
	for(ll i=0; i<root.size(); i++){
		bst=max(length(v,root[i]),bst);
		//cout<<root[i];
	}
	if(bst==0){
		cout<<bst+1;
	}
	else{
	//cout<<length(v,1)<<endl;
		cout<<bst;
	}

}