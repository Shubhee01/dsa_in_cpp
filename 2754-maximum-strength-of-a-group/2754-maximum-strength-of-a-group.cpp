class Solution {
public:
    long long f(int i, vector<int>& nums, long long p, int taken){
        if(i<0){
            if(taken>0){
                return p;
            }
            return -1e9;
        }
        long long val=f(i-1,nums,p*nums[i],taken+1);
        long long notval=f(i-1,nums,p,taken);
        return max(val,notval);
    }
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        return f(n-1,nums,1,0);
    }
};