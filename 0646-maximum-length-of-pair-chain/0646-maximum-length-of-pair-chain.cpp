class Solution {
public:
    int f(int i, vector<vector<int>>& pairs, int prev, vector<vector<int>> &dp){
        if(i==pairs.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take=0;
        int nottake=f(i+1,pairs,prev,dp);
        if(prev==-1 || pairs[i][0]>pairs[prev][1]){
            take=1+f(i+1,pairs,i,dp);
        }
        return dp[i][prev+1]=max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        return f(0,pairs,-1,dp);
    }
};