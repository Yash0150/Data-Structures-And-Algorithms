#include<bits/stdc++.h>
using namespace std;
#define ll long long

class node{
	public:
		ll data;
		node* next;

		node(ll d){
			data=d;
			next=NULL;
		}
};

void insert_at_head(node*&head,ll data){
	node*n= new node(data);
	n->next=head;
	head=n;
}

bool search_iteratively(node*head,ll k){
	node*temp=head;
	while(temp!=NULL){
		if(temp->data==k){
			return true;
		}
		temp=temp->next;
	}
	return false;

}

bool search_recursively(node*head,ll k){
	if(head==NULL){
		return false;
	}
	else if(head->data==k){
		return true;
	}
	else{
		search_recursively(head->next,k);
	}
	//return false;
}

void print(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	node*head=NULL;
	insert_at_head(head,10);
	insert_at_head(head,20);
	insert_at_head(head,30);

	if(search_recursively(head,10)){
		cout<<"PReSENt";
	}
	else{
		cout<<"UffF";
	}

	if(search_iteratively(head,0)){
		cout<<"PReSENt";
	}
	else{
		cout<<"UffF";
	}	
}