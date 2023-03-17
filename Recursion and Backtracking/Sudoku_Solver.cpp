class Solution {
public:
    bool isValid(vector<vector<char>>& v,char ch,int row,int col){
            for(int i=0;i<9;i++){
            if(v[i][col]==ch || v[row][i]==ch || v[3*(row/3)+(i/3)][3*(col/3) +(i%3)]==ch){
                return false;
            }
        }
        return true;
    }
    bool help(vector<vector<char>>& v){
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(v,c,i,j)){
                            v[i][j]=c;
                            if(help(v)){
                                return true;
                            }
                            v[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        help(board);
        return;
    }
};