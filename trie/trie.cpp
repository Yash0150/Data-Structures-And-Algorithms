#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node*>

class node{
	public:
		char data;
		hashmap h;
		bool isTerminal;

		node(char d){
			data=d;
			isTerminal=false;
		}
};

class Trie{
	node* root;
	public:
		Trie(){
			root=new node('\0');
		}

		void addword(string s){
			node* temp=root;
			int n=s.size();
			for(int i=0; i<n; i++){
				char ch=s[i];

				if(temp->h.count(ch)==0){
					node* child=new node(ch);
					temp->h[ch]=child;
					temp=child;
				}
				else{
					temp=temp->h[ch];
				}
			}
			temp->isTerminal=true;
		}

		bool lookup(string s){
			node*temp=root;
			int n=s.size();
			for(int i=0; i<n; i++){
				char ch=s[i];

				if(temp->h.count(ch)==0){
					return false;
				}
				else{
					temp=temp->h[ch];
				}
			}

			return temp->isTerminal;
		}
};

int main(){
	Trie t;
	string A[5]={"app","bds","vpp","serr","ser"};

	for(int i=0; i<5; i++){
		string a=A[i];
		t.addword(A[i]);
	}

	string s="seer";

	if(t.lookup(s)){
		cout<<'y';
	}
}