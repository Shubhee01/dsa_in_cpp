class Solution {
public:
    int f(vector<int>& nums, int goal){
        int n=nums.size();
        queue<int> q;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
            sum+=nums[i];
            while(!q.empty() && sum>goal){
                sum-=q.front();
                q.pop();
            }
            count+=q.size();
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};