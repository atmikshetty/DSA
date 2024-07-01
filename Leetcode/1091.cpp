class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }

        if(grid[0][0]==0 && n==1 && m==1){  //2x2
            return 1;
        }

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e7));

        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1,n-1};

        dist[source.first][source.second] = 0;
        q.push({1,{source.first, source.second}});

        int delRow[] = {0,1,-1,0,1,-1,1,-1};
        int delCol[] = {1,0,0,-1,1,1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i=0;i<8;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == destination.first && ncol == destination.second) return 1 + dis;
                    q.push({1+dis, {nrow,ncol}});
                }
            }
        }
        if(source.first == destination.first && source.second == destination.second) return 0;
        return -1;
    }
};