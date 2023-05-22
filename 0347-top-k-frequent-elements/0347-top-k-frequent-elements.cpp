class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        map<int,int>m;
        vector<int> v;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            q.push({i.second,i.first});
        }
        while(k>0){
            v.push_back(q.top().second);
            q.pop();
            k--;
        }
        return v;
    }
};