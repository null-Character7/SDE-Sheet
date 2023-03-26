class Solution {
public:

    int singleNonDuplicate(vector<int>& v) {

        int n=v.size();
        if(n==1){
            return v[0];
        }

        int lo=0,hi=n-1;
        int mid;

        while(lo<=hi){
            mid=lo+(hi-lo)/2;

            // Answer, else in the end the answer will be stored in hi
            if((mid==0 || v[mid]!=v[mid-1]) && (mid==n-1 || v[mid]!=v[mid+1] )){
                return v[mid];
            }

            if(mid%2==0){
                // Left Side
                if(mid>0 && v[mid]==v[mid-1]){
                    hi=mid-1;
                }
                // Right Side
                else{
                    lo=mid+1;
                }
            }

            else{
                // Right Side
                if(mid>0 && v[mid]==v[mid-1]){
                    lo=mid+1; 
                }
                // Left Side
                else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};