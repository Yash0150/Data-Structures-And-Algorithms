#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='['){
			st.push(s[i]);
		}
		if(s[i]==')'){
			if(!st.empty() && st.top()=='('){
				st.pop();
			}
			else{
				cout<<"No";
				return 0;
			}
		}
		if(!st.empty() && s[i]=='}'){
			if(st.top()=='{'){
				st.pop();
			}
			else{
				cout<<"No";
				return 0;
			}
		}
		if(!st.empty() && s[i]==']'){
			if(st.top()=='['){
				st.pop();
			}
			else{
				cout<<"No";
				return 0;
			}
		}
	}
	if(st.empty()){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}