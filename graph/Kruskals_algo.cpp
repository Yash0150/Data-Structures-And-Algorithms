#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph{
	 vector<pair<int,pair<int,int>>> adjList;

	public:
		Graph(){

		};
		void addEdge(int src, int des, int weight){

			adjList.push_back(make_pair(weight,make_pair(des,weight)));
		}

		void Kruskal(){
			sort(adjList.begin(),adjList.end());
		}
};

int main(){
	Graph g;
	int n,e;
	cin>>n>>e;
	for(int i=0; i<e; i++){
		int src,des,w;
		cin>>src>>des>>w;
		g.addEdge(src,des,w);
	}
}