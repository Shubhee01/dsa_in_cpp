class Solution {
public:
    long long N=1e9+7;
    int f(int i, int n, int fuel, vector<int>& nums, vector<vector<int>> &dp){
        if(fuel<0){
            return 0;
        }
        if(dp[i][fuel]!=-1){
            return dp[i][fuel];
        }
        long long take=0;
        for(int k=0;k<nums.size();k++){
            if(k!=i){
                take=(take+f(k,n,fuel-abs(nums[k]-nums[i]),nums,dp))%N;
            }
        }
        return dp[i][fuel]=(i==n)+take;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size()+1,vector<int>(fuel+1,-1));
        return f(start,finish,fuel,locations,dp);
    }
};