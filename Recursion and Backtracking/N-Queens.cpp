class Solution {
public:
    void help(int col,int n,vector<string>& v,vector<vector<string>>& ans,vector<int>& left,vector<int>& LtoRDiagonal,vector<int>& RtoLDiagonal){
		// Base Case
        if(col==n){
            ans.push_back(v); // If the algo is able to place all n Queens only then it will come till here, else it will be breaked before 
            return;
        }
		
		// Cheking all the rows in that column if Queen can be placed there
        for(int i=0;i<n;i++){
			
            if(!left[i] && !LtoRDiagonal[i+col] && !RtoLDiagonal[n-1+col-i]){ // To place the queen, there should not be any queen in that row & diagonal
                v[i][col]='Q';
                left[i]=1;
                LtoRDiagonal[i+col]=1;
                RtoLDiagonal[n-1+col-i]=1;
                help(col+1,n,v,ans,left,LtoRDiagonal,RtoLDiagonal); // Recursive Call
				
				// Backtracking
                v[i][col]='.';
                left[i]=0;
                LtoRDiagonal[i+col]=0;
                RtoLDiagonal[n-1+col-i]=0;
            }
        }
		// If we have checked all the rows int that column, and we cannt place any queen there, then it will return from here, no furthur executation in that path
		
    }
	
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++){
            s+='.';
        }
        vector<int> left(n,0),LtoRDiagonal(2*n-1),RtoLDiagonal(2*n-1);
        vector<vector<string>> ans;
        vector<string> v(n,s);
        help(0,n,v,ans,left,LtoRDiagonal,RtoLDiagonal);
        return ans;
    }
};