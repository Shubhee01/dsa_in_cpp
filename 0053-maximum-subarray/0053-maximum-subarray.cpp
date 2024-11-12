class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int cursum=0;
        int n=nums.size();
        bool pos=false;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos=true;
            }
            cursum+=nums[i];
            if(cursum<0){
                cursum=0;
            }
            maxsum=max(cursum,maxsum);
        }
        if(!pos){
            maxsum=*max_element(nums.begin(),nums.end());
        }
        return maxsum;
    }
};