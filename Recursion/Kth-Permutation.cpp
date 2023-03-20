#define ll long long
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        ll fact=1;
        for(ll i=1;i<n;i++){
            v.push_back(i);
            fact*=i;
        }
        v.push_back(n);
        string ans="";
        k--;
        while(1){
            string s=to_string(v[k/fact]);
            ans+=s;
            v.erase(v.begin()+(k/fact));
            k%=fact;
            if(v.size()==0){
                break;
            }
            fact/=v.size();
        }
        return ans;
    }
};