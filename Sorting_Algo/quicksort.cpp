#include<bits/stdc++.h>
using namespace std;

int swap(int *x, int *y){
	int temp = *x;
	*y = *x;
	*x = temp;
}

int partition(vector <int> &v, int low, int high){
	int pivot = v[high];
	int i = (low- 1);
	for(int j = low; j <= high- 1; j++){
		if (v[j] <= pivot){
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i+1], v[high]);
	return (i + 1);
}

int partition_r(vector <int> &v, int low, int high) 
{   srand(time(NULL)); 
    int random = low + rand() % (high - low); 
    swap(v[random], v[high]); 
    return partition(v, low, high); 
} 

int quicksort(vector <int> &v, int low, int high){
	if ( low < high){

		int pi= partition( v, low ,high );

		quicksort( v, low , pi- 1 );
		quicksort(v ,pi+ 1, high );
	}
}
		
int main(void){
	vector <int> v;
	for(int i = 0; i < 5; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	quicksort(v,0,4);
	for(int i = 0; i < 5; i++){
		cout<<v[i]<<" ";
	}
}
	
