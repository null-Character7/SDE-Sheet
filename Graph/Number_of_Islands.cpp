class Solution {
private:
    // Directions
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};

    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j,int n,int m){

        vis[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                // Cheking if valid position or not, already visited or not, land or water
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]=='0' || vis[nx][ny]==1){
                    continue;
                }
                else{
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++; // Number ofr connected components
                    bfs(grid,vis,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};