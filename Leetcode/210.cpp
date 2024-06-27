class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // solve using kahn's bfs algorithm
        // same as 1 but this time return the order as well
        // convert into adjacency list first

        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);  // reverse her v depends on u
        }

        // find out in degrees
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        // find out the nodes with zero indegree
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // find out the order for other nodes
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(ans.size() == numCourses) return ans;
        else return {};
    }
};