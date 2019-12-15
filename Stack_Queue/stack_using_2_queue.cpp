#include<bits/stdc++.h>
using namespace std;
#define ll long long 

template<typename T>
class Stack{
	private:
		queue<T>q1,q2;
		int curr_size=0;
	public:
		/*void push(T d){
			curr_size++; 
  
    	    q2.push(d); 

        	while (!q1.empty()) 
        	{ 
            	q2.push(q1.front()); 
	            q1.pop(); 
    	    } 
  
        	queue<T> q = q1; 
	        q1 = q2; 
    	    q2 = q; 

   		} 

    	void pop(){ 
	        if (q1.empty()) 
    	        return ; 
    	    q1.pop(); 
    	    curr_size--; 
    	}

    	T top(){ 
	        if (q1.empty()) 
    	        return -1; 
    	    return q1.front(); 
    	} 
  
    	T size(){ 
    	    return curr_size; 
    	} 
};  
*/
		void pop(){ 
        	if (q1.empty()) 
            	return; 
	  
    	    while (q1.size() != 1) { 
	            q2.push(q1.front()); 
    	        q1.pop(); 
        	} 
  
	        q1.pop(); 
    	    curr_size--; 
  	
    	    queue<int> q = q1; 
        	q1 = q2; 
        	q2 = q; 
    	} 
  
    	void push(int x) 
    	{ 
        	q1.push(x); 
       		curr_size++; 
    	} 
  
    	int top() 
    	{ 
        	if (q1.empty()) 
        	    return -1; 
  	
        	while( q1.size() != 1 ) 
    	   	{ 
           		q2.push(q1.front()); 
           		q1.pop(); 
        	}  
           
        	int temp = q1.front(); 
          
        	q1.pop(); 
       	    q2.push(temp); 
  
        	queue<int> q = q1; 
        	q1 = q2; 
        	q2 = q; 
        	return temp; 
  	  	} 
  
    	int size() 
    	{ 
        	return curr_size; 
    	} 
}; 
  
int main() 
{ 
    Stack<int> s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
    cout << "current size: " << s.size()  
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
  
    cout << "current size: " << s.size()  
         << endl; 
    return 0; 
} 

