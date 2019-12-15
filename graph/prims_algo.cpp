#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Graph{

	map<int,list<pair<int,int>>> adjList;

	public:
		Graph(){

		};
		void addEdge(int u,int v,int w){
			adjList[u].push_back(make_pair(v,w));
			adjList[v].push_back(make_pair(u,w));
		}

		int findMinVertex(int weight[],bool visited[],int v){
			int MinVertex=-1;

			for(int i=0; i<v; i++){
				if(!visited[i] && (MinVertex==-1 || weight[i]<weight[MinVertex])){
					MinVertex=i;
				}
			}
			return MinVertex;
		}

		void Prims(int v){
			bool visited[v];
			int parent[v]={0};
			int weight[v]={0};
			for(int i=0; i<v; i++){
				visited[i]=false;
				weight[i]=INT_MAX;
			}

			parent[0]=-1;
			weight[0]=0;

			for(int i=0; i<v; i++){
				int minIndex= findMinVertex(weight,visited,v);

				visited[minIndex]=true;
				for(auto j : adjList[minIndex]){
					if(!visited[j.first]){
						if(weight[j.first]>j.second){
							parent[j.first]=minIndex;
							weight[j.first]=j.second;
						}
					}
				}
			}
			for(int i=1; i<v; i++){
				cout<<i<<"--"<<parent[i]<<"-weight-"<<weight[i]<<endl;
			}
		}
};

int main(){
	Graph g;
	int n,e;
	cin>>n>>e;
	for(int i=0; i<e; i++){
		int x,y,z;
		cin>>x>>y>>z;
		g.addEdge(x,y,z);
	}
	g.Prims(n);

}