class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        queue<int> vp;
        queue<int> vn;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                vn.push(nums[i]);
            }else{
                vp.push(nums[i]);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans.push_back(vp.front());
                vp.pop();
            }else{
                ans.push_back(vn.front());
                vn.pop();
            }
        }
        return ans;
    }
};