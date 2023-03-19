class Solution{
    public:
    void help(int i,int j,string move,vector<string>& ans,vector<vector<int>> &v,vector<vector<int>>& vis){
        int n=v.size();

        // Base Case, Reached the target
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }

        // Down
        if(i+1<n && vis[i+1][j]==0  && v[i+1][j]==1){
            vis[i][j]=1;
            move.push_back('D');
            help(i+1,j,move,ans,v,vis);
            vis[i][j]=0;
            move.pop_back();
        }

        // Left
        if(j-1>=0 && vis[i][j-1]==0 && v[i][j-1]==1){
            vis[i][j]=1; // marking this position as visited before procceding so that we dont stuck in infinite loop of up-down-up-down :)
            move.push_back('L');
            help(i,j-1,move,ans,v,vis);

            // backtracking
            vis[i][j]=0;
            move.pop_back();
        }
        
        // Right
        if(j+1<n && vis[i][j+1]==0 && v[i][j+1]==1){
            vis[i][j]=1;
            move.push_back('R');
            help(i,j+1,move,ans,v,vis);
            vis[i][j]=0;
            move.pop_back();
        }

        // Up
        if(i-1>=0 && vis[i-1][j]==0 && v[i-1][j]==1){
            vis[i][j]=1;
            move.push_back('U');
            help(i-1,j,move,ans,v,vis);
            vis[i][j]=0;
            move.pop_back();
        }
        
    }
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        string move;
        int i=0,j=0;
        if(v[i][j]==0){
            return ans;
        }
        help(i,j,move,ans,v,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends