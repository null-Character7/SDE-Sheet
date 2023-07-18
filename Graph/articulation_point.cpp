int timer=0;

    void dfs(int node,int parent,vector<int>& tin,vector<int>& low,vector<int> adj[],vector<int>& mark,vector<int>& vis){
        vis[node]=1;
        low[node]=tin[node]=timer++; 
        int child=0;
        for(auto it:adj[node]){
            if(parent==it){
                continue; // apart from parent
            }
            if(vis[it]==0){
                child++; // to handle the starting case when parent == -1
                dfs(it,node,tin,low,adj,mark,vis);
                low[node]=min(low[node],low[it]); // min lowest time of insertion of adjacent nodes
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
            }
            else{
                low[node]=min(low[node],tin[it]); // min time of insertion of adjacent nodes, not lowest time as here vertex is removed
            }
        }
        if(child>1 && parent==-1){
            mark[node]=1; // starting case parent == -1 && more than 1 unvisited child
        }
    }

    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n,0);
        vector<int> tin(n,0); // time of insertion during dfs
        vector<int> low(n,0); // minimum of all adjacent nodes apart from parent and visited
        vector<int> mark(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,adj,mark,vis);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()==0){
            return {-1};
        }
        return ans;
    }