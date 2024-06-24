#include<bits/stdc++.h>

int main(){
    // List approach Space: O(2 x No of Edges)
    int n,m;
    cin >> n >> m;
    vector<int> adjList[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);  // at index u push v
        adjList[v].push_back(u);  // at index v push u, for directed remove this line and space will be O(E)
    }
}