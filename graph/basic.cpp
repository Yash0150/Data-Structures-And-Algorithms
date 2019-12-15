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

		void bfs(T src){

			queue<T> q;
			map<T,bool> visited;

			q.push(src);
			visited[src]=true;

			while(!q.empty()){

				T node = q.front();
				cout<<node<<" ";
				q.pop();

				for(auto neighbour:adjList[node]){
					if(!visited[neighbour]){
						q.push(neighbour);
						visited[neighbour]=true;
					}
				}
			}
		}

		void bfsdis(T src){

			queue<T> q;
			map<T,bool> visited;
			map<T,int> distance;
			map<T,T> parent;

			for(auto i : adjList){
				distance[i.first]=INT_MAX;
			}

			q.push(src);
			visited[src]=true;
			distance[src]=0;
			parent[src]=src;

			while(!q.empty()){

				T node = q.front();
				//cout<<node<<" ";
				q.pop();

				for(auto neighbour:adjList[node]){
					if(!visited[neighbour]){
						q.push(neighbour);
						visited[neighbour]=true;
						distance[neighbour]=distance[node]+1;
						parent[neighbour]=node;
					}
				}
			}

			for(auto i:adjList){
				T node = i.first;
				cout<<"Dist of "<<node<<" from "<<src<<"is "<<distance[node]<<endl;
			}
		}

		void dfshelper(T node,map<T,bool> &visited){
			visited[node]=true;
			cout<<node<<"-";

			for(auto neighbour : adjList[node]){
				if(!visited[neighbour]){
					dfshelper(neighbour,visited);
				}
			}
		}

		void dfs(T src){
			map<T,bool> visited;
			dfshelper(src,visited);
		}
	
};

int main(){

	//Graph<string> g;
	/*g.addEdge("Putin","Trump",false);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Modi","Trump");

	//g.print();

	g.bfsdis("Putin");*/
	Graph<int> g;
	g.addEdge(0,1,false);
	g.addEdge(1,2,false);
	g.addEdge(0,4,false);
	g.addEdge(2,4,false);
	g.addEdge(2,3,false);
	g.addEdge(3,4,false);
	g.addEdge(3,5,false);
	g.dfs(0);

}