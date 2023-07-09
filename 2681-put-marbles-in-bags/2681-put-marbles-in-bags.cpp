class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> v;
        k--;
        int n=weights.size();
        for(int i=0;i<n-1;i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(),v.end());
        long long a=0;
        long long b=0;
        n=v.size();
        for(int i=0;i<k;i++){
            a+=v[i];
            b+=v[n-i-1];
        }
        return b-a;
    }
};