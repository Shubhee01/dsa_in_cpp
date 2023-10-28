class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n);
        vector<int> s(n);
        for(int i=0;i<n;i++){
            if(i==0){
                p[i]=nums[i];
            }else{
                p[i]=min(p[i-1],nums[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                s[i]=nums[i];
            }else{
                s[i]=min(s[i+1],nums[i]);
            }
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            if(nums[i]==p[i] || s[i]==nums[i]){
                continue;
            }
            mini=min(mini,(p[i]+s[i]+nums[i]));
            // cout<<p[i]<<" "<<s[i]<<endl;
        }
        if(mini==1e9){
            return -1;
        }
        return mini;
    }
};