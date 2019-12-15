#include<bits/stdc++.h>
using namespace std;
#define ll long long

class node{
    public:
        int data;
        node* next;
        
        node(int d){
            data = d;
            next = NULL;
        }
};
void insert_at_tail(node* &head,int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new node(d);
}
void build(node* &head,int n){
    for(int i=0; i<n; i++){
        int d;
        cin>>d;
        insert_at_tail(head,d);
    }
}
int main(){
	//node*head=NULL;
	node*head1=NULL,*head2=NULL;
	int n1,n2;
	cin>>n1;
	build(head1,n1);
	cin>>n2;
	build(head2,n2);
	if(n1>n2){
		int d=n1-n2;
		node*temp1=head1;
		while(d!=0){
			temp1=temp1->next;
			d--;
		}
		//cout<<d<<" "<<temp1->data;
		node*temp2=head2;
		while(temp1!=NULL && temp2!=NULL){
			if(temp1->data==temp2->data){
				cout<<temp1->data;
				break;
			}
			//cout<<temp1->data<<" "<<temp2->data;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		
	}
	else{
		int d=n1-n2;
		node*temp2=head2;
		while(d!=1){
			temp2=temp2->next;
			d--;
		}
		node*temp1=head1;
		while(temp1->data!=temp2->data){
			temp1=temp1->next;
			temp2=temp2->next;
		}
		cout<<temp1->data;
	}
}