int spanningTree(int n, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    // weight node
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int weight = it.first;
        if (vis[node])
        {
            continue;
        }
        sum += weight;
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int w = it[1];
            if (vis[adjNode] == 0)
            {
                pq.push({w, adjNode});
            }
        }
    }
    return sum;
}