class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=nums[i]; 
        int index=i+1; 
        while(index<nums.size() && nums[index]==nums[i]){
            sum+=nums[index];
            index++;
        }
        while(index<nums.size() && nums[index]==nums[i]+1){
            index++;
        }
        int take=sum+f(index,nums,dp);
        int nottake=f(i+1,nums,dp);
        return dp[i]=max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        sort(nums.begin(),nums.end());
        return f(0,nums,dp);
    }
};