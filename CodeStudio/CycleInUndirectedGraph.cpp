#include<bits/stdc++.h>

bool dfs(int node, int parent, int visited[], vector<int> adj[]){
    visited[node]=1;
    for(auto adjacentNode: adj[node]){
        if(!visited[adjacentNode]){
            if(dfs(adjacentNode, node, visited, adj)) return true;
        }
        else if(parent!=adjacentNode) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    int visited[n+1] = {0};

    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i, -1, visited, adj)) return "Yes";
        }
    }
    return "No";
}
