class Solution {
public:
    
    void help(int index,vector<vector<int>>& ans,vector<int> nums){
        // Base Case
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){ // trying from index (not 0) so that no repeatation is there in the list 
            
            swap(nums[i],nums[index]); // fixing the position index, and trying all the elements which can come in that position
            
            help(index+1,ans,nums); // Recursion 
            
            swap(nums[i],nums[index]); // Backtracking
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(0,ans,nums);
        return ans;
    }
};