#include<bits/stdc++.h>
using namespace std;
#define ll long long

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    char d;
    cin>>d;

    if(d=='l'){
        return NULL;
    }
    node * root = new node(1);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

int main(){
	ll t;
	cin>>t;
	while(t--){
		node* root=NULL;
		root=buildTree();

		cout<<height(root);
	}
}