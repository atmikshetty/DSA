vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){   // checking the adjacent nodes of the current nodes
            if(!vis[it]){  // checking if previously visited
                vis[it] = 1;
                q.push(it);
            }
        }   
    }
    return bfs;
}