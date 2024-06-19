#include<bits/stdc++.h>
using namespace std

int main(){
    // LIFO
    stack<int> st;
    st.push(10);
    st.push(20);  // adds 10 and 20 to the stack
    st.top();    // Takes out the top element
    st.pop();   // removes the top element
    st.size();  // size of the stack which is basically top + 1
}