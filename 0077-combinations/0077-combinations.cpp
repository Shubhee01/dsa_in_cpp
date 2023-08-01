class Solution {
public:
    void f(int i,int k,vector<int> &v,vector<int> &nums,vector<vector<int>> &ans){
        if(i==nums.size()){
            if(v.size()==k){
                ans.push_back(v);
            }
            return;
        }
        v.push_back(nums[i]);
        f(i+1,k,v,nums,ans);
        v.pop_back();
        f(i+1,k,v,nums,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        f(0,k,v,nums,ans);
        return ans;
    }
};