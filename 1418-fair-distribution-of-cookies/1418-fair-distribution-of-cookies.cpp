class Solution {
public:
    int ans=1e9;
    void f(int i, vector<int>& nums, vector<int>& m, int k){
        if(i==nums.size()){
            ans=min(ans,*max_element(m.begin(),m.end()));
            return;
        }
        for(int j=0;j<k;j++){
            m[j]+=nums[i];
            f(i+1,nums,m,k);
            m[j]-=nums[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> m(k,0);
        f(0,cookies,m,k);
        return ans;
    }
};