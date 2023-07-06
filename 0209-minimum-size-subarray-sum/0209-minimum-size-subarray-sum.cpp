class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<int> q;
        int sum=0;
        int mini=INT_MAX;
        for(auto i:nums){
            q.push(i);
            sum+=i;
            while(target<=sum){
                if(q.size()<mini && target<=sum){
                    mini=q.size();
                }
                sum-=q.front();
                q.pop();
            }
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};