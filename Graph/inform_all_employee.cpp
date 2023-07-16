#define ll long long
class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& informTime) {
        queue<pair<ll,ll>> q;
        vector<ll> adjlist[n];
        for(ll i=0;i<n;i++){
            if(manager[i]==-1){
                continue;
            }
            adjlist[manager[i]].push_back(i);
        }
        
        ll ans=0;
        vector<ll> vis(n,0);
        q.push({head,0});
        // bfs
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ll node=it.first;
            ll time=it.second;
            // storing the max time
            ans=max(ans,time);
            for(auto child:adjlist[node]){
                if(vis[child]==1){
                    continue;
                }
                // adding the current required time with previously used time
                q.push({child,informTime[node]+time});
                vis[child]=1;
            }
        }
        return ans;
    }
};