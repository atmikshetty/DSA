#include<bits/stdc++.h>

int main(){
    //  Adjacency Matrix approach takes O(N2)
    int n,m;
    cin >> n >> m;
    int matrix[n+1][m+1];  // matrix of size N x M
    for(int i=0;i<m;i++){
        int u,v; // connecting the edges
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // intersection marked as 1;
    }
    return 0;
}