class Solution {
public:
    int N=1e9+7;
    vector<vector<long long>> dp;
    long long ans(vector<int> nums,int n){
        if(n<=2){
            return 1;
        }
        vector<int> l;
        vector<int> r;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[0]){
                r.push_back(nums[i]);
            }else{
                l.push_back(nums[i]);
            }
        }
        long long nl=l.size();
        long long nr=r.size();
        long long left=ans(l,nl)%N;
        long long right=ans(r,nr)%N;
        n=n-1;
        return (((left*right)%N)*dp[n][nl])%N;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1);        
        for(int i = 0; i <= n; i++) {            
            dp[i]=vector<long long>(i+1, 1);            
            for(int j=1;j<i;j++) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%N;
        }
        return (ans(nums,n)-1)%N;
    }
};