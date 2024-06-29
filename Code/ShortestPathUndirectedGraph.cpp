//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // Creating the adjacency list
        vector<int> adj[N+1];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // both side since its an undirected graph
        }
            
            // store the distance as infinite and src distance as 0
            vector<int> dist(N, INT_MAX);
            dist[src] =0;
            queue<int> q;
            q.push(src);
            
            // BFS
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(dist[node]+1 < dist[it]){
                        dist[it] = 1 + dist[node];
                        q.push(it);
                    }
                }
            }
            
            vector<int> ans(N,-1);
            for(int i=0;i<dist.size();i++){
                if(dist[i] != INT_MAX){
                    ans[i] = dist[i];
                }
            }
            
            return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends