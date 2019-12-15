#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
class Graph{

	map<T,list<pair<T,ll>>> adjList;

	public:

		Graph(){

		}
		void addEdge(T u,T v,ll w){
			adjList[u].push_back(make_pair(v,w));
			adjList[v].push_back(make_pair(u,w));
		}

		ll dfshelper(T node,map<T,bool> &visited,ll A[],ll B[]){
			visited[node]=true;
			//cout<<node<<"-";

			for(auto neighbour : adjList[node]){
				if(!visited[neighbour.first]){
					B[neighbour.first]=neighbour.second;
					A[node]+=dfshelper(neighbour.first,visited,A,B);
				}
			}
			return A[node];
		}
		void dfs(ll A[],ll B[]){
			map<T,bool> visited;

			for(auto i:adjList){
				T city=i.first;
				if(!visited[city]){
					dfshelper(city,visited,A,B);
				}
			}
		}

};

int main(){
	ll t;
	cin>>t;
	ll tt=t;
	while(t--){
		Graph<ll> g;
		ll n,a,b,c,cnt=0;
		cin>>n;
		ll count[n+1]={0};
		ll  dis[n+1]={0};
		count[n]=1;
		for(int i=1; i<n;i++){
			count[i]++;
			cin>>a>>b>>c;
			g.addEdge(a,b,c);
		}
		g.dfs(count,dis);
		for(int i=1; i<=n;i++){
			cnt+=2*(min(count[i],n-count[i]))*dis[i];
		}
		cout<<"Case #"<<tt-t<<": "<<cnt<<endl;
	}
}