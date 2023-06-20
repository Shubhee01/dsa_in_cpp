class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        long long sum=0;
        int j=0;
        int m=(2*k)+1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if((i-j+1)==m){
                ans[i-k]=sum/m;
                sum-=nums[j];
                j++;
            }
        }
        return ans;
    }
};