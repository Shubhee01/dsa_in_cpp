class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int,int> dp;
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int val=arr[i]-diff;
            if(dp.find(val)!=dp.end()){
                dp[arr[i]]=1+dp[val];
            }
            ans=max(ans,dp[arr[i]]);
        }
        return ans+1;
    }
};