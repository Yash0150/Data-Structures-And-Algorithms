#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
class Graph{

	map<T,list<T>> adjList;

	public:

		Graph(){

		}
		void addEdge(T u,T v,bool bidir=true){
			adjList[u].push_back(v);
			if(bidir){
				adjList[v].push_back(u);
			}
		}

		void dfshelper(T node,map<T,bool> &visited){
			visited[node]=true;
			//cout<<node<<"-";

			for(auto neighbour : adjList[node]){
				if(!visited[neighbour]){
					dfshelper(neighbour,visited);
				}
			}
		}

		void dfs(T src){
			int components=1;
			map<T,bool> visited;
			dfshelper(src,visited);

			for(auto i:adjList){
				T city=i.first;
				if(!visited[city]){
					dfshelper(src,visited);
					components++;
				}
			}
			cout<<components;
		}
};


int main(){
	Graph<string> g;
	g.addEdge("delhi","jaipur",false);
	g.addEdge("delhi","pune",false);
	g.addEdge("pune","jaipur",false);
	g.addEdge("jaipur","kerela",false);
	g.addEdge("kerela","mumbai",false);
	g.addEdge("mumbai","jaipur",false);
	g.addEdge("mumbai","pune",false);
	g.addEdge("andaman","nicobar",false);
	g.addEdge("delhi","punjab",false);

	g.dfs("delhi");

}