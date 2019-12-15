#include<bits/stdc++.h> 
using namespace std; 
//long long count = 0;
long long cnt=0;

class NODE{
	public:
		long long val;
  		long long height;
  		long long count;
  		NODE* left;
  		NODE* right;
  		NODE(long long v){
    		val = v;
    		height = 1;
    		left = NULL;
    		right = NULL;
    		count = 1;
    }
};

long long getHeight(NODE* root){
  if(root == NULL){
    return 0;
  }
  return root->height;
}

long long getCount(NODE* root){
  if(root == NULL){
    return 0;
  }
  return root->count;
}

long long getBFactor(NODE* root){
  if(root == NULL){
    return 0;
  }
  return getHeight(root->left) - getHeight(root->right);
}

NODE* rightRotate(NODE* root){
  NODE* x = root->left;
  NODE* y = x->right;
  x->right = root;
  root->left = y;
  root->height = 1 +max(getHeight(root->left),getHeight(root->right));
  root->count = 1 + getCount(root->left) + getCount(root->right);
  x->height = 1 + max(getHeight(x->left),getHeight(x->right));
  x->count = 1 + getCount(x->left) + getCount(x->right);
  return x;
}

NODE* leftRotate(NODE* root){
  NODE* x = root->right;
  NODE* y = x->left;
  x->left = root;
  root->right = y;
  root->height = 1 + max(getHeight(root->left),getHeight(root->right));
  root->count = 1 + getCount(root->left) + getCount(root->right);
  x->height = 1 + max(getHeight(x->left),getHeight(x->right));
  x->count = 1 + getCount(x->left) + getCount(x->right);
  return x;
}


NODE* insert(NODE* root,long long val){
  if(root == NULL){
    root = new NODE(val);
    return root;
  }else if(val < root->val){
    root->left = insert(root->left,val);
  }else if(val > root->val){
    root->right = insert(root->right,val);
  }
  root->height = 1 + max(getHeight(root->left),getHeight(root->right));
  root->count = 1 + getCount(root->left) + getCount(root->right);
  long long bFactor = getBFactor(root);
  if(bFactor > 1 && val < root->left->val){
    return rightRotate(root);
  }
  if(bFactor > 1 && val > root->left->val){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if(bFactor < -1 && val > root->right->val){
    return leftRotate(root);
  }
  if(bFactor < -1 && val < root->right->val){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

long long search(NODE* root,long long val){
  if(root == NULL){
    return 0;
  }
  if(val == root->val){
    return (1 + getCount(root->left));
    //return true;
  }else if(val < root->val){
    return search(root->left,val);
  }else{
    return (1 + getCount(root->left))+ search(root->right,val);
  }
}

int main(){
	long long t;
	NODE* root = NULL;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		if(a==1){
			insert(root,b);
		}
		else{
			//cnt=0;
			cout<<search(root,b);/*){
				cout<<cnt<<endl;
			}
			else{
				cout<<cnt;//"Data tidak ada"<<endl;
			}
		*/}
	}
}



