#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf=INT_MAX;
ll dp[1001][1001];
ll sum(vector <ll> &v,ll s,ll e){
    ll ans=0;
    for(ll i=s; i<=e;i++){
        ans+=v[i];
        ans%100;
    }
    return ans%100;  
}
ll mix(vector<ll> &v, ll s,ll e, ll n){
    if(s>=e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    dp[s][e]= inf;
    for(ll i=s; i<=e; i++){
        dp[s][e]=min(dp[s][e],mix(v,s,i,n)+mix(v,i+1,e,n)+sum(v,s,i)*sum(v,i+1,e));
    }
    return dp[s][e];
}
/*ll mix(vector<ll> &v,ll n){
    for(int i=0; i<n; i++){
        dp[i][i]=0;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            dp[i][j]=min(ans,dp[i-1][j]+dp[i][j-1]+sum(v,i,j)*sum(v,i+1,e));
        }
    }
    return dp[0][n-1];
}*/
int main(){
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    ll ans=mix(v,0,n-1,n);
    //cout<<ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}