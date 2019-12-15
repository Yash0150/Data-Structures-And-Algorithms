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

		int bfsdis(T src, T dest){

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
			T temp=dest;
			while(temp!=src){
				cout<<temp<<"<-";
				temp=parent[temp];
			}
			cout<<src;
			cout<<endl;
			return distance[dest];
		}
	
};

int main(){

	Graph<int> g;
	int board[50]={0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;

	for(int u=0;u<=36; u++){
		for(int dice=1; dice<=6; dice++){
			int v=u+dice+board[u+dice];
			g.addEdge(u,v,false);
		}
	}

	cout<<"The shortest dis is "<<g.bfsdis(0,36);
}