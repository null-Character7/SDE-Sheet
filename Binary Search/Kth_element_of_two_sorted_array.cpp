int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m){
            return kthElement(arr2,arr1,m,n,k);
        }

        // Doing binary search on first array, and wrt to cut in first array finding the cut in second array
        int lo=max(0,k-m),hi=min(k,n);
        int cut1=n,cut2;

        while(lo<=hi){

            cut1=lo+((hi-lo)>>1);
            cut2=k-cut1;

            int ul=INT_MIN,ur=INT_MAX;
            int bl=INT_MIN,br=INT_MAX;

            if(cut1>0){
                ul=arr1[cut1-1];
            }
            if(cut2>0){
                bl=arr2[cut2-1];
            }
            if(cut1<n){
                ur=arr1[cut1];
            }
            if(cut2<m){
                br=arr2[cut2];
            }

            if(ul<=br && bl<=ur){
                return max(ul,bl); // Got the answer
            }
            else if(ul>br){
                hi=cut1-1; // have to decrease the left element of the cut in first array
            }
            else if(bl>ur){
                lo=cut1+1; // // have to increase the right element of the cut in first array
            }
        }
        return -1;
    }