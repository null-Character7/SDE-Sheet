class Solution {
public:
    void dfs(int node,int parent,vector<int>& tin,vector<int>& low,vector<int> adj[],vector<vector<int>>& bridges,vector<int>& vis,int timer){
        vis[node]=1;
        low[node]=tin[node]=timer++; // initialising both insertion time using timer
        for(auto it:adj[node]){
            if(parent==it){
                continue; // apart from parent
            }
            if(vis[it]==0){
                dfs(it,node,tin,low,adj,bridges,vis,timer);
                low[node]=min(low[node],low[it]); // min lowest time of insertion of adjacent nodes
                if(low[it]>tin[node]){
                    bridges.push_back({node,it}); // it can not be reached through other node if this edge is broken 
                }
            }
            else{
                low[node]=min(low[node],low[it]); // min lowest time of insertion of adjacent nodes
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& v) {
        vector<int> adj[n];
        for(int i=0;i<v.size();i++){
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }
        int timer=0;
        vector<int> vis(n,0);
        vector<int> tin(n,0); // time of insertion
        vector<int> low(n,0); // min lowest time of insertion of all adjacent nodes apart from parent
        vector<vector<int>> bridges;
        dfs(0,-1,tin,low,adj,bridges,vis,timer);
        return bridges;
    }
};