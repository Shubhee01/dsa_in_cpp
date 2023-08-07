class Solution {
public:
    void f(int i, int target, vector<vector<int>> &ans, vector<int> &v, vector<int> &nums){
        if(target==0){
            if(find(ans.begin(),ans.end(),v)==ans.end()){
                ans.push_back(v);
            }
            return;
        }
        for(int ind=i;ind<nums.size();ind++){
            if(ind>i && nums[ind]==nums[ind-1]){
                continue;
            }
            if(nums[ind]>target){
                break;
            }
            v.push_back(nums[ind]);
            f(ind+1,target-nums[ind],ans,v,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        f(0,target,ans,v,candidates);
        return ans;
    }
};