#include<bits/stdc++.h>
using namespace std;

//  takes log(n)
// multiset is only sorted not unique
// unordered set not sorted only unique
int main(){
    set<int>s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    cout << s;
}