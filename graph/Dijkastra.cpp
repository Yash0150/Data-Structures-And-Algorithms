#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
class Graph{
	unordered_map<T,list<pair<T,int>>> m;

public:
	void addEdge(T u,T v, int dis,bool bidir=true){
		m[u].push_back(make_pair(v,dis));
		if(bidir){
			m[v].push_back(make_pair(u,dis));
		}
	}

	void printAdj(){
		for(auto j : m){
			cout<<j.first<<"->";

			for(auto l : j.second){
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void DijkstraSSSP(T src){
		unordered_map<T,int> dist;

		for(auto j:m){
			dist[j.first]=INT_MAX;
		}

		set<pair<int,T>> s;

		dist[src]=0;
		s.insert(make_pair(0,src));

		while(!s.empty()){
			auto p= *(s.begin());
			T node=p.second;

			int nodeDis=p.first;
			s.erase(s.begin());

			for(auto childpair : m[node]){
				if(nodeDis+ childpair.second < dist[childpair.first]){

					T dest=childpair.first;
					auto f= s.find(make_pair(dist[dest],dest));
					if(f!=s.end()){
						s.erase(f);
					}

					dist[dest]=nodeDis+ childpair.second;
					s.insert(make_pair(dist[dest],dest));
				}

			}
			for(auto j : dist){
				cout<<j.first<<" is located at "<<j.second<<endl;
			}
		}
	}
};

int main(){
	Graph<int> g;

	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);
	g.DijkstraSSSP(1);
}