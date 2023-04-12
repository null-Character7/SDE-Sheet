class Solution {
    void bfs(vector<int> adj[],int vis[],int start,vector<int>& ans){

        // Marking the starting node as visited
        vis[start]=1;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int cur=q.front();
            ans.push_back(cur);
            q.pop();
            for(auto child:adj[cur]){
                // if not visited then visit
                if(!vis[child]){
                    q.push(child);
                    vis[child]=1; // mark as visited
                }
                
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        int vis[v]={0};
        bfs(adj,vis,0,ans);
        // for not connected components we have run a for loop for each node, and run it if it is not visited
        return ans;
    }
};