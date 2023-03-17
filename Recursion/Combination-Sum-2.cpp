class Solution {
public:
    void help(int index,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& v){
        
        if(target==0){
            ans.push_back(v); // No base case required, only when target is zero push it in the list
        }
      
        for(int i=index;i<arr.size();i++){
            if(i!=index && arr[i]==arr[i-1]){
                continue; // skipping same numbers, except the index itself 
            }
          
            if(arr[i]>target){
                break; // Adding only when the number is less than target, else break
            }
          
            v.push_back(arr[i]); // take
            help(i+1,target-arr[i],arr,ans,v);
          
            v.pop_back(); // Not take,will be executed in next loop
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        vector<int> v;
        help(0,target,arr,ans,v);
        return ans;
    }
};