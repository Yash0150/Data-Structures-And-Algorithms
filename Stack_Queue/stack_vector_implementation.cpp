#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
class Stack{
	private:
		vector<T>v;
		//vector<T>v;
	public:
		void push(T d){
		//void push(T d){
			v.push_back(d);
		}
		bool isempty(){
			v.empty();
		}
		void pop(){
			v.pop_back();
		}
		T top(){
		//T top(){
			return v[v.size()-1];
		}
};

int main(){
	Stack<char> s;
	//Stack s;
	int n=5;
	//cin>>n;
	for(int i=65; i<70; i++){
		s.push(i);
	}

	while(s.isempty()==false){
		cout<<s.top()<<" ";
		s.pop();
	}
}