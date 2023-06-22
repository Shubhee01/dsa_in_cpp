class Solution {
public:
    int f(int i, vector<int>& prices, int fee, bool buy, vector<vector<int>>& dp){
        if(i==prices.size()-1){
            if(buy==false){
                return prices[i]-fee;
            }
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int take=-1e9;
        int nottake=f(i+1,prices,fee,buy,dp);
        if(buy==true){
            take=f(i+1,prices,fee,!buy,dp)-prices[i];
        }else{
            take=f(i+1,prices,fee,!buy,dp)+prices[i]-fee;
        }
        return dp[i][buy]=max(take,nottake);
    }
    int maxProfit(vector<int>& prices, int fee) {
        bool buy=true;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,prices,fee,buy,dp);
    }
};