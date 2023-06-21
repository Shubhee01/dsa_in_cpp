class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        long long den=0;
        long long num=0;
        for(auto i:v){
            num+=((long long)i.first*(long long)i.second);
            den+=(long long)i.second;
        }
        long long mid=0;
        long long tot=0;
        int i=0;
        while(tot<((den+1)/2) && i<n){
            tot+=v[i].second;
            mid=v[i].first;
            i++;
        }
        long long sum=0;
        for(auto i:v){
            sum+=(abs((long long)i.first-mid)*(long long)i.second);
        }
        return sum;
    }
};