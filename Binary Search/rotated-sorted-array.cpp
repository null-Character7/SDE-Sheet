#define ll long long
#define endl '\n'
class Solution {
public:
    int search(vector<int>& v, int target) {
        ll n=v.size();
        ll hi=n-1,lo=0;
        ll mid;

        while(lo<=hi){

            mid=lo+(hi-lo)/2;
            if(v[mid]==target){
                return mid;
            }

            // The logic is any of the half either left half or the right half will be sorted 

            // Left half is sorted
            if(v[lo]<=v[mid]){ 
                // the target is in the left half
                if(target>=v[lo] && target<=v[mid]){
                    hi=mid-1;
                }
                // target is not in the left half
                else{
                    lo=mid+1;
                }
            }
            // Right half is sorted
            else{
                // the target is in the right half
                if(target>=v[mid] && target<=v[hi]){
                    lo=mid+1;
                }
                // target is not in the right half
                else{
                    hi=mid-1;
                }
            }

        }

        return -1;
    }
};