#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> m;
	int n,k;
	cin>>n>>k;
	int A[n], B[n];
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		A[i]=a;
		B[i]=A[i];
		m.insert(make_pair(a,i));
	}
	//map<int,int>::iterator it;
	//for(it=m.begin(); it!=m.end(); it++){
	//	cout<<'.'<<it->first<<" "<<it->second<<endl;
	//}
	//m.insert(make_pair(1,3));
	int i=0;
	sort(B,B+n);
	reverse(B,B+n);
	while(k--){
		for(; i<n; i++){
			if(B[i]!=A[i]){
				int t=m[B[i]];
				m[B[i]]=m[A[i]];
				m[A[i]]=t;
				swap(A[t],A[i]);
				i++;
				break;
			}
		}
	}
	for(int i=0; i<n; i++){
			cout<<A[i]<<" ";
		}
}