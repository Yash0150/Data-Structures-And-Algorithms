#include<bits/stdc++.h>
using namespace std;
#define ll long long;

class Edge{
	public:
		int src;
		int dest;
};

class Graph{
	public:
		int v,e;
		Graph(int V,int E){
			v=V;
			e=E;
		}
		Edge edge[100];
};

int findpar(int parent[],int i){
	if(parent[i]==-1){
		return i;
	}
	return findpar(parent,parent[i]);
}

void Union(int parent[],int x, int y){
	int xset= findpar(parent,x);
	int yset= findpar(parent,y);

	if(xset!=yset){
		parent[xset]=yset;
	}
}

int isCyclic(Graph g){
	int parent[g.v]={0};
	for(int i=0; i<g.v; i++){
		parent[i]=-1;
	}

	for(int i=0; i<g.e; i++){
		int x= findpar(parent,g.edge[i].src);
		int y= findpar(parent,g.edge[i].dest);

		if(x==y){
			return 1;
		}
		Union(parent,x,y);
	}

}

int main(){
	int v=4,e=4;

	Graph g(v,e);

	g.edge[0].src=0;
	g.edge[0].dest=1;

	g.edge[1].src=1;
	g.edge[1].dest=2;

	g.edge[2].src=0;
	g.edge[2].dest=2;

	g.edge[3].src=0;
	g.edge[3].dest=3;

	if(isCyclic(g)){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}


}