#include<bits/stdc++.h>
using namespace std

int main(){
    // FIFO
    queue<int> q;
    q.push(10);
    q.push(20);
    q.pop();   // gives 10
    q.front(); // gives 20
    q.size();
    q.empty();   // checks whether queue is empty or not 
}