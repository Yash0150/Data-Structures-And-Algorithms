#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	stack<int> s;
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a;
		if(a==1){
			if(s.empty()){
				cout<<"No Code"<<endl;
			}
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
		else{
			cin>>b;
			s.push(b);
		}
	}
}