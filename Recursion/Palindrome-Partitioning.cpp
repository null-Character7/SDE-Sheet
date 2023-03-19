class Solution {
public:

    bool isPalindrome(string s,int start,int end){
        int i=start,j=end;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void help(vector<vector<string>>& ans,vector<string>& v,int index,string& s){

        // Base Case
        if(index==s.length()){
            ans.push_back(v);
            return;
        }

        // Trying partitioning in all possible places
        for(int i=index;i<s.length();i++){

            // Only when the first part is Palindrome we will go further
            if(isPalindrome(s,index,i)){
                
                v.push_back(s.substr(index,i-index+1));
                help(ans,v,i+1,s); // Recursion, to check if the remain part can be partitioned 

                // No partition there
                v.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        help(ans,v,0,s);
        return ans;
    }
};