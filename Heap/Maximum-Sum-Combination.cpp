vector<int> solve(vector<int> &a, vector<int> &b, int k) {

    int n=a.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;

    // Initialisation, max sum will be the sum of maximum elements of both arrays
    s.insert({n-1,n-1});
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});

    vector<int> ans;

    while(k--){
        int x=pq.top().first;
        int u=pq.top().second.first;
        int d=pq.top().second.second;
        pq.pop();
        ans.push_back(x);

        // Taking corner from upside
        if(u>0 && d>0 && s.find({u-1,d})==s.end()){ // Cheking if this already exists in the priority queue or not, so that there is no copy
            pq.push({a[u-1]+b[d],{u-1,d}});
            s.insert({u-1,d}); // Marking this pair as done
        }

        // Taking corner from downside 
        if(u>0 && d>0 && s.find({u,d-1})==s.end()){  // Cheking if this already exists in the priority queue or not, so that there is no copy
            pq.push({a[u]+b[d-1],{u,d-1}});
            s.insert({u,d-1}); // Marking this pair as done
        }
    }
    return ans;
}