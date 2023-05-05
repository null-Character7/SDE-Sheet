class Solution {
public:

    void dfs(int start,vector<int>& vis,vector<int> adj[]){
        vis[start]=1;
        for(auto it:adj[start]){
            if(vis[it]){
                continue;
            }
            dfs(it,vis,adj);
        }
    }

    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
