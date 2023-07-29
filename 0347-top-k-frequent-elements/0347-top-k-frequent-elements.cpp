class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        priority_queue<pair<int,int>> q;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            q.push({i.second,i.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};