class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int dp[n][2][501];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                int temp = nums[j]-nums[i];
                if(temp>0){
                    dp[i][0][temp] = max(dp[j][0][temp]+1,2);
                    ans = max(ans,dp[i][0][temp]);
                }
                else{
                    dp[i][1][abs(temp)] = max(dp[j][1][abs(temp)]+1,2);
                    ans = max(ans,dp[i][1][abs(temp)]);
                }
            }
        }
        return ans;
    }
};