#include<bits/stdc++.h>
using namespace std;

int area(int A[],int n){
	stack<int>s;
	int i=0;
	int max_area=0;
	while(i<n){
		if(s.empty() || A[s.top()]<=A[i]){
			s.push(i++);
		}
		else{
			int top=s.top();
			s.pop();

			int area_=A[top]*((s.empty())?i:(i-s.top()-1));
			max_area=max(area_,max_area);
		}
	}
	while(!s.empty()){
		int top=s.top();
		s.pop();

		int area_=A[top]*((s.empty())?i:(i-s.top()-1));
		max_area=max(area_,max_area);
	}
	return max_area;
}

int main(){
	int A[4][4]={ {0, 1, 1, 0}, 
                   {1, 1, 1, 1}, 
                   {1, 1, 1, 1}, 
                   {1, 1, 0, 0}, 
                };
    int n=4,m=4;
    int dp[m]={0};
    int bst=0;
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		if(A[i][j]==0){
    			dp[j]=0;
    		}
    		else{
    			dp[j]+=1;
    		}
    	}
    	bst=max(bst,area(dp,m));
    } 
    cout<<bst;
}