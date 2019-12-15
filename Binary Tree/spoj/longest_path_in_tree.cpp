#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll node=0;

class Graph{
	map<ll,list<ll>> m;
	
public:
	Graph(){

	}
	
	void addEdge(ll u,ll v,bool bidir=true){
		m[u].push_back(v);
		if(bidir){
			m[v].push_back(u);
		}
	}


	ll length(ll src){
		queue<ll> q;
		map<ll,bool> visited;
		map<ll,ll> distance;
		map<ll,ll> parent;

		for(auto i : m){
			distance[i.first]=INT_MAX;
		}
		q.push(src);
		visited[src]=true;
		distance[src]=0;
		parent[src]=src;
		ll bst=0;
		while(!q.empty()){
			node = q.front();
			//cout<<node<<" ";
			q.pop();

			for(auto neighbour:m[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
					distance[neighbour]=distance[node]+1;
					parent[neighbour]=node;
					bst=max(distance[neighbour],bst);
				}
			}
		}
		return bst;
	}
};

int main(){
	Graph g;
	ll n,m;
	cin>>n;
	m=n;
	ll u,v;
	while(--n){
		cin>>u>>v;
		g.addEdge(u,v);
	}
	ll h1=g.length(1);
	ll h2=g.length(node);
	cout<<h2<<endl;
}

