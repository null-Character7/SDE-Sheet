class Solution {
public:
  
    void help(int index,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& v){
        // Base case
        if(index>=arr.size()){
            if(target==0){
                ans.push_back(v); // if subset sum is equal to target, then push to the list, else return
            }
            return;
        }
      
        if(arr[index]<=target){ // only take the index which are less then target
            v.push_back(arr[index]);
            help(index,target-arr[index],arr,ans,v);
          
            v.pop_back(); // Not take
        }
        
        help(index+1,target,arr,ans,v);
    }
  
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        help(0,target,arr,ans,v);
        return ans;
    }
};
