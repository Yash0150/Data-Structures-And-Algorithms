#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    int A[n],B[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[j]>A[i]){
                cout<<A[j]<<" ";
            }
            break;
        }
        cout<<-1<<" ";
    }
    cout<<-1;
}