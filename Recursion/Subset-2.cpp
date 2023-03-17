class Solution {
public:
  
    void help(int index,vector<int>& v,vector<vector<int>>& ans,vector<int> arr){
        
        ans.push_back(v); // Here Base case is not required, all the subsets will be pushed in answer
        
        for(int i=index;i<arr.size();i++){
            
            if(i!=index && arr[i]==arr[i-1]){ 
                continue; // skipping the equal elements, except the index itself
            }
            
            v.push_back(arr[i]); // take
            help(i+1,v,ans,arr);
            
            v.pop_back(); // not take,it will be executed next time in the for loop
        }
        
    }
  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end()); // sorting so that equal elements remain side by side
        
        help(0,v,ans,nums);
        
        return ans;
    }
};