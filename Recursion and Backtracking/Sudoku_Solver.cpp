class Solution {
public:
    
    bool isValid(vector<vector<char>>& v,char ch,int row,int col){
            for(int i=0;i<9;i++){
            if(v[i][col]==ch || v[row][i]==ch || v[3*(row/3)+(i/3)][3*(col/3) +(i%3)]==ch){ // Cheking in that row + column + sub-boxes
                return false;
            }
        }
        return true;
    }
    
    bool help(vector<vector<char>>& v){
        int n=v.size();
        // Traversing in that puzzle box
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='.'){               // if the box is empty only then we need to check
                    for(char c='1';c<='9';c++){
                        // trying all possible numbers in that empty box
                        if(isValid(v,c,i,j)){   
                            v[i][j]=c;
                            if(help(v)){       // Recursive call to check if after putting this number here it can be solved further for other empty boxes
                                return true;
                            }
                            v[i][j]='.';       // If it's not possible then the code will come till here, Here we are undoing the changes, Backtracking
                        }
                        
                    }
                    return false; // If no number is valid in this position ,retunr False
                }
            }
        }
        return true; // If no empty box is there then return True
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        help(board);
        return;
    }
};
