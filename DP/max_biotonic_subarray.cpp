#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int cnt=INT_MIN;
        int ans=1;
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        for(int i=0; i<n-1; i++){
            if((i&1)==0){
                if(A[i+1]<A[i]){
                    ans++;
                }
                else{
                    cnt=max(cnt,ans);
                    ans=1;
                }
            }
            else{
                if(A[i+1]>A[i]){
                    ans++;
                }
                else{
                    cnt=max(cnt,ans);
                    ans=1;
                }
            }
        }
        cnt=max(cnt,ans);
        cout<<cnt<<endl;
    }
}