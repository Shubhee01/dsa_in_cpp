class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=1;
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==x){
                k++;
            }else{
                if(k<3){
                    return x;
                }
                k=1;
                x=nums[i];
            }
        }
        if(k<3){
            return nums[nums.size()-1];
        }
        return -1;
    }
};