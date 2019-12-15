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
		void print(){
			for(auto i:adjList){
				cout<<i.first<<"-";

				for(T entry:i.second){
					cout<<entry<<",";
				}
				cout<<endl;
			}
		}

		void dfshelper(T node,map<T,bool> &visited,list<T> &ordering){
			visited[node]=true;

			for(T neighbour : adjList[node]){
				if(!visited[neighbour]){
					dfshelper(neighbour,visited,ordering);
				}
			}

			ordering.push_front(node);
		}

		void dfstopologicalsort(){
			map<T,bool> visited;
			list<T> ordering;

			for(auto i: adjList){
				T node= i.first;

				if(!visited[node]){
					dfshelper(node,visited,ordering);
				}
			}

			for(auto i : ordering){
				cout<<i<<"->";
			}
		}

		void bfstopologicalsort(){
			queue<T> q;
			map<T,bool> visited;
			map<T,int> indegree;

			for(auto i: adjList){
				T node= i.first;
				visited[node]=false;
				indegree[node]=0;
			}

			for(auto i: adjList){
				T node= i.first;
				for(T v:adjList[node]){
					indegree[v]++;
				}			
			}

			for(auto i: adjList){
				T node = i.first;

				if(indegree[node]==0){
					q.push(node);
				}
			}

			while(!q.empty()){
				T node=q.front();
				q.pop();

				cout<<node<<"->";

				for(T neighbour : adjList[node]){
					indegree[neighbour]--;

					if(indegree[neighbour]==0){
						q.push(neighbour);
					}
				}
			}
		}
};

int main(){
	Graph<string> g;
	g.addEdge("eng","pl",false);
	g.addEdge("maths","pl",false);
	g.addEdge("pl","html",false);
	g.addEdge("pl","python",false);
	g.addEdge("pl","java",false);
	g.addEdge("pl","js",false);
	g.addEdge("python","webd",false);
	g.addEdge("html","css",false);
	g.addEdge("css","js",false);
	g.addEdge("js","webd",false);
	g.bfstopologicalsort();
}