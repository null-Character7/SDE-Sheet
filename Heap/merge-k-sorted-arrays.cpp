#define pii pair<int,int>

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int n)
    {
        // first one to store number, second one to store row number
        priority_queue<pii,vector<pii>,greater<pii>> pq;

        for(int i=0;i<n;i++){
            pq.push({arr[i][0],i}); // storing only the first element, as others will be larger than the first one
        }

        vector<int> ans;
        vector<int> ind(n,0); // storing column position in each row

        while(pq.size()!=0){

            auto x=pq.top();
            ans.push_back(x.first);
            pq.pop();

            // Increasing the column position of the row from which top element belongs
            int cur=++ind[x.second];

            // storing the current element in the priority queue if it is valid (not out of bound)
            if(cur<arr[x.second].size()){
                pq.push({arr[x.second][cur],x.second});
            }

        }
        
        return ans;
    }
};