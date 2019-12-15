#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll x1,x2,x3,x4;
	ll y1,y2,y3,y4;
	cin>>x1>>y1>>x2>>y2;

	ll dis=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	ll m1=abs(x1-x2);
	ll m2=abs(y1-y2);

	if(m1==0){
		x3=x2+dis;
		x4=x1+dis;
		y3=y2;
		y4=y1;
		cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
	}
	else if(m2==0){
		y3=y2+dis;
		y4=y1+dis;
		x3=x2;
		x4=x1;
		cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
	}
	else if(m1==m2){
		x3=x1;
		y3=y2;
		x4=x2;
		y4=y1;
		cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}