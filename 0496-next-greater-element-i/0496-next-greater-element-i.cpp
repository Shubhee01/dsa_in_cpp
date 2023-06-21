class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        m[nums2[nums2.size()-1]]=-1;
        stack<int> s;
        s.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--){
            if(s.empty()){
                s.push(nums2[i]);
                continue;
            }
            // cout<<m[s.top()]<<endl;
            while(!s.empty() && nums2[i]>=s.top()){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]]=-1;
            }else{
                m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};