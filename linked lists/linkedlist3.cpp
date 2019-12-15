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

void insert_at_tail(node*&head,ll data){
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

void reverse_linked_list(node*&head){
	node* curr=head;
	node* prev=NULL;
	node*  n;
	while(curr!=NULL){
		n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}
	head=prev;
}

node* reverse_linked_list_recursively(node*head){
	if(head->next==NULL || head==NULL){
		return head;
	}

	node*small_head=reverse_linked_list_recursively(head->next);
	node*curr=head;
	curr->next->next=curr;
	curr->next=NULL;

	return small_head;
}

node* mid_point(node*head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node*fast=head->next;
	node*slow=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

node* k_node_from_end(node*&head,ll k){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node*fast=head;
	node*slow=head;
	while(k!=1){
		fast=fast->next;
		//cout<<'a';
		if(fast==NULL){
			return NULL;
		}
		k--;
	}
	while(fast->next!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	return slow;

}

void build_linked_list(node*&head){
	ll d;
	cin>>d;

	while(d!=-1){
		insert_at_tail(head,d);
		
		cin>>d;
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

istream& operator>>(istream &is,node*&head){
	build_linked_list(head);
	return is;
}

ostream& operator<<(ostream &os,node*head){
	print(head);
	return os;
}

int main(){
	node*head=NULL;
	node*head1=NULL,*head2=NULL;
	build_linked_list(head);
	print(head);
	cout<<endl;
	//cin>>head1>>head2;
	//cout<<head1<<endl<<head2;

	//head1=reverse_linked_list_recursively(head);
	//print(head1);
	//print(head);

	//head2=mid_point(head);
	//cout<<head2->data;

	head2=k_node_from_end(head,3);
	if(head2!=NULL){
		cout<<head2->data;
	}
	else{
		cout<<"NOT EXISTING";
	}
}