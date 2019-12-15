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

node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	else{
		node*c;
		if((a->data)<(b->data)){
			c=a;
			c->next=merge(a->next,b);
		}
		else{
			c=b;
			c->next=merge(a,b->next);
		}
		return c;
	}
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

node* merge_sort(node*head){
	if(head==NULL || head->next==NULL){
		return head;
	}

	node* mid=mid_point(head);

	node*a=head;
	node*b=mid->next;
	mid->next=NULL;

	a=merge_sort(a);
	b=merge_sort(b);

	node* c=merge(a,b);
	return c;
}

void insert_at_tail(node*&head,int data){
	if(head==NULL){
		head=new node(data);
		return ;
	}
	node*tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=new node(data);
}

void build_linked_list(node*&head,ll k){
	while(k!=0){
		ll d;
		cin>>d;
		insert_at_tail(head,d);
		k--;
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

int main(){
	int n;
	cin>>n;
	node*head1=NULL,*head2=NULL;
	build_linked_list(head1,n);
	print(head1);
	//build_linked_list(head2);
	node*head3=merge_sort(head1);

	print(head3);
}