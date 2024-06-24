class Solution {
public:

    void dfs(int node, vector<int> &visited, vector<int> ls[]){
        visited[node] = 1;
        for(auto it: ls[node]){
            if(!visited[it]){
                dfs(it, visited, ls);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // Creating an adjacency list
        int n = isConnected.size();
        vector<int> ls[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,ls);
            }
        }
        return count;
    }
};