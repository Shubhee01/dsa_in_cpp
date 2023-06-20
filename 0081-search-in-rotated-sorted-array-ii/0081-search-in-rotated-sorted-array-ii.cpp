class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            return nums[n-1]==target;
        }
        int high=n-1;
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;
            // cout<<low<<" "<<high<<" "<<mid<<endl;
            if(nums[mid]==target){
                return true;
            }
            if(nums[low]==target){
                return true;
            }
            if(nums[high]==target){
                return true;
            }
            if(low<=high && nums[high]==nums[low]){
                low++;
                high--;
                continue;
            }
            if(nums[mid]>=nums[low]){
                if(target>nums[low] && target<nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(target<nums[high] && target>nums[mid]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};