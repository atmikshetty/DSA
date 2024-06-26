#include <bits/stdc++.h> 

void dfs(int node, int visited[], vector<int> adj[], stack<int>& st){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // Create an adjacency list
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> st;
    int visited[v] = {0};
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i, visited, adj, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}