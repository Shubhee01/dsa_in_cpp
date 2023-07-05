class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int,int> m;
        int j=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            while(j<n && m[0]>1){
                m[nums[j]]--;
                j++;
            }
            if(count<m[1] && m[0]==1){
                count=m[1];
            }
        }
        if(m[1]==nums.size()){
            count=m[1]-1;
        }
        return count;
    }
};