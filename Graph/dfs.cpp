class Solution {
    void dfs(vector<int> adj[],int vis[],vector<int>& ans,int node){

        // before entering to every node
        ans.push_back(node);
        vis[node]=1; // marking every starting node as visited

        for(int child:adj[node]){
            // before entering to its child nodes
            // if not visited then 
            if(!vis[child]){
                // before entering the child
                dfs(adj,vis,ans,child);
                // after exiting from the child
            }
        }
        // before exiting from the node
    }

  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        int vis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i])
            dfs(adj,vis,ans,i);
        }
        return ans;
    }
};