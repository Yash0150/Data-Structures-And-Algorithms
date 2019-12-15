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

		bool iscyclicBFS(T src){
			map<T,bool> visited;
			map<T,int> parent;
			queue<T> q;

			q.push(src);
			parent[src]=src;
			visited[src]=true;

			while(!q.empty()){
				T node=q.front();
				q.pop();

				for(T neighbour : adjList[node]){
					if(visited[neighbour]==true && parent[node]!=neighbour){
						return true;
					}
					else if(visited[neighbour]==false){
						visited[neighbour]=true;
						parent[neighbour]=node;
						q.push(neighbour);
					}
				}
			}
			return false;
		}

		bool iscyclicHelper(T node,map<T,bool> visited,map<T,bool> inStack){
			visited[node]=true;
			inStack[node]=true;

			for(T neighbour : adjList[node]){
				if((!visited[neighbour] && iscyclicHelper(neighbour,visited,inStack))|| inStack[neighbour]){
					return true;
				}
			}

			inStack[node]=false;
			return false;
		}

		bool iscyclicDFS(){
			map<T,bool> visited;
			map<T,bool> inStack;

			for(auto i : adjList){
				T node = i.first;
				if(visited[node]==false){
					bool present = iscyclicHelper(node,visited,inStack);
				}
			}
		}
};

int main(){
	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
//	g.addEdge(4,1);

	if(g.iscyclicDFS()){
		cout<<"YES";
	}
	else{
		cout<<"No";
	}

}
