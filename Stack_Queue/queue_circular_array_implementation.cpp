#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>

class Queue{
	private:
		T* arr;
		int front,rear,max_size,cur_size;
	public:
		Queue(int ds){
			front=0;
			max_size=ds;
			rear=max_size-1;
			arr=new T[max_size];
			cur_size=0;
		}
		bool isFull(){
			return cur_size==max_size;
		}

		bool isEmpty(){
			return cur_size==0;
		}

		void push(T d){
			if(!(isFull())){
				rear=(rear+1)%max_size;
				arr[rear]=d;
				cur_size++;
			}
		}

		void pop(){
			if(!isEmpty()){
				front=(front+1)%max_size;
				cur_size--;
			}

		}

		int getFront(){
			return arr[front];
		}
};

int main(){
	int n=5;
	//cin>>n;
	Queue<int> q(4);

	for(int i=1; i<n; i++){
		q.push(i);
	}
	q.pop();
	q.push(8);

	while(!q.isEmpty()){
		cout<<q.getFront()<<" ";
		q.pop();
	}
}