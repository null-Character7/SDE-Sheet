class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node,int par,vector<int> adj[],vector<int>& vis){
        totalVis[node]=1;
        vis[node]=1;
        bool check=false;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                check |= dfs(adjNode,node,adj,vis);
            }
            else if(vis[adjNode] && adjNode!=par){
                return true;
            }
        }
        return check;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // Code here
        vector<int> vis(n,0);
        vector<int> totalVis(n,0);
        bool check=false;
        for(int i=0;i<n;i++){
            if(!totalVis[i]){
                check |= dfs(i,-1,adj,vis);
            }
        }
        return check;
    }
};