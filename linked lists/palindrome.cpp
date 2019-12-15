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
void build(node* &head,node* &head2,int n){
    for(int i=0; i<n; i++){
        int d;
        cin>>d;
        insert_at_tail(head,d);
        insert_at_tail(head2,d);
    }
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
void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
	node* head1=NULL;
	node* head2=NULL;
	int n;
	cin>>n;
	build(head1,head2,n);
	reverse_linked_list(head1);
	while(head2->next!=NULL){
		if(head1->data!=head2->data){
			cout<<"False";
			return 0;
		}
		head1=head1->next;
		head2=head2->next;
	}
	cout<<"True";
	return 0;
}