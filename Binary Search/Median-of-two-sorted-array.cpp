class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()){
            return findMedianSortedArrays(b,a);
        }
        int n1=a.size(),n2=b.size();
        int lo=0,hi=n1;

        // doing binary search to find where the cut will be placed to get median

        while(lo<=hi){

            // cut in the first array
            int cut1=lo+(hi-lo)/2;

            // cut in the second array, as there should be half number of total elements in the left of the median
            int cut2=(n2+n1+1)/2-cut1;

            int left1=INT_MIN,left2=INT_MIN,right1=INT_MAX,right2=INT_MAX;
            if(cut1>0){
                left1=a[cut1-1];
            }
            if(cut2>0){
                left2=b[cut2-1];
            }
            if(cut1<n1){
                right1=a[cut1];
            }
            if(cut2<n2){
                right2=b[cut2];
            }
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    return ((max(left1,left2)+min(right1,right2))/2.00); // when total size is even median is half of two mid elements
                }
                else{
                    return max(left1,left2); // when total size is odd median is the mid element
                }
            }
            else{
                // we have to decrease left1 and increase right2, so shift leftward int the first array
                if(left1>right2){
                    hi=cut1-1;
                }
                else{
                    lo=cut1+1;
                }
            }
        }
        return -1;
    }
};