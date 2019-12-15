#include<bits/stdc++.h>
using namespace std;
#define ll long long

void reverse_stack_using_2_stacks(stack<int>&s){
	stack<int>s1,s2;
	while(!s.empty()){
		s1.push(s.top());
		s.pop();
	}
	while(!s1.empty()){
		s2.push(s1.top());       //SEE TRANSFER FUNCTION...........////
		s1.pop();
	}
	while(!s2.empty()){
		s.push(s2.top());
		s2.pop();
	}
}

void reverse_stack_using_1_stacks(stack<int>&s){
	stack<int>s1;
	for(int i=0; i<s.size(); i++){
		int top=s.top();
		s.pop();
		int curr=s.size()-i;
		while(curr>0){
			s1.push(s.top());
			s.pop();
			curr--;
		}
		s.push(top);
		while(s1.size()!=0){
			s.push(s1.top());
			s1.pop();
		}
	}
}

void insert_at_bottom(stack<int>&s,int n){
	if(s.empty()){
		s.push(n);
		return;
	}

	int top=s.top();
	s.pop();
	insert_at_bottom(s,n);
	s.push(top);
}

void reverse_stack_using_recursion(stack<int>&s){
	if(s.empty()){
		return;
	}

	int top=s.top();
	s.pop();
	reverse_stack_using_recursion(s);
	insert_at_bottom(s,top);
}

int main(){
	int n;
	cin>>n;
	stack<int>s;
	for(int i=0; i<n; i++){
		s.push(i);
	}
	//reverse_stack_using_2_stacks(s);
	//reverse_stack_using_1_stacks(s);
	reverse_stack_using_recursion(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}