#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    // cout << v[0] << " " << v.at(0) << " " << v.back();

    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << endl;
    }
    for(auto it: v){
        cout << it;
    }
}