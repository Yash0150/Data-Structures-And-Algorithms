#include<bits/stdc++.h>
using namespace std;
#define ll long long;

class node{
	public:
		int data;
		node* next;

		node(int d){
			data=d;
			next=NULL;
		}
};

int len(node*head){
	int l=0;
	node*temp=head;
	while(temp!=NULL){
		l++;
		temp=temp->next;
	}
	return l;
}

void insert_at_head(node*&head,int data){
	node*n= new node(data);
	n->next=head;
	head=n;
}

void insert_at_tail(node*&head,int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node*tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=new node(data);
}

void insert_at_p(node*&head,int data,int p){
	if(head==NULL){
		insert_at_head(head,data);
	}
	else if(p>len(head)){
		insert_at_tail(head,data);
	}
	else{
		int jump=1;
		node*temp=head;
		node*n=new node(data);
		while(jump<=p-1){
			temp=temp->next;
			jump++;
		}
		n->next=temp->next;
		temp->next=n;
	}
}

void delete_at_head(node*&head){
	if(head==NULL){
		return;
	}
	else{
		node*temp=head;
		head=head->next;
		delete temp;
	}
	return;
}

void delete_at_tail(node*head){
	if(head==NULL){
		return;
	}
	else{
		node*temp=head;
		node*prev;
		while(temp->next!=NULL){
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		delete temp;
		return;
	}
}

void delete_at_p(node*head,int p){
	if(head==NULL){
		return;
	}
	else if(p>len(head)){
		delete_at_tail(head);
	}
	else if(p==1){
		delete_at_head(head);
	}
	else{
		int jump=1;
		node*temp=head;
		node*prev=NULL;
		while(jump!=p){
			prev=temp;
			temp=temp->next;
			jump++;
		}
		prev->next=temp->next;
		delete temp;
		return;
	}
}

void print(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}

/*void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}*/

int main(){
	node* head=NULL;
	insert_at_head(head,10);
	insert_at_head(head,20);
	insert_at_head(head,30);

	print(head);

	insert_at_p(head,40,2);
	insert_at_tail(head,50);

	print(head);

	delete_at_head(head);
	delete_at_tail(head);
	delete_at_p(head,2);

	print(head);
}