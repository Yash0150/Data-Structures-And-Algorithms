#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	string s="abbacdeb";
	//cin>>s;
	int n=s.size();

	int visited[256];
	int curr_size=1;
	int max_size=0;

	memset(visited,-1,sizeof(visited));

	visited[s[0]]=0;
	for(int i=1; i<n; i++){
		int last_occ=visited[s[i]];

		if(last_occ==-1 || (i-curr_size)>last_occ){
			curr_size++;
			max_size=max(max_size,curr_size);
		}
		else{
			max_size=max(max_size,curr_size);
			curr_size= i -last_occ;
		}
		visited[s[i]]=i;
	}
	cout<<max_size;
}