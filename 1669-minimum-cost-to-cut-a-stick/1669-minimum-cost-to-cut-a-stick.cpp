class Solution {
public:
    int ans(int i,int j,vector<int> &v,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            mini=min(mini,v[j+1]-v[i-1]+ans(i,k-1,v,dp)+ans(k+1,j,v,dp));
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int>v;
        v.push_back(0);
        for(auto i:cuts){
            v.push_back(i);
        }
        v.push_back(n);
        vector<vector<int>> dp(v.size(),vector<int>(v.size(),-1));
        return ans(1,v.size()-2,v,dp);
    }
};