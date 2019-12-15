#include<iostream>
#include"hashing.h"
using namespace std;

int main(){
///Fruit, 100 Key = string, price= int

    Hashtable<int> h(7);
    h.insert("Mango",100);
    h.insert("Apple",170);
    h.insert("Guava",140);
    h.insert("Banana",130);
    h.insert("Chiku",120);

    h.print();

    int *ans=h.search("Mango");
    cout<<*ans;


return 0;
}

