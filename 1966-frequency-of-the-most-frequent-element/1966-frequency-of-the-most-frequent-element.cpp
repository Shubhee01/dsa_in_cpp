class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {\
        sort(nums.begin(),nums.end());
        int j=0;
        long long total=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            while(j<i && (long long)((long long)nums[i]*(long long)(i-j+1))>total+k){
                total-=nums[j];
                j++;
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};