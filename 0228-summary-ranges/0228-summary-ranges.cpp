class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()){
            return ans;
        }
        if(nums.size()==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int ind=nums[0];
        int start=nums[0];
        string a="";
        for(int i=1;i<nums.size();i++){
            if(ind+1==nums[i]){
                ind++;
                continue;
            }else{
                if(start==ind){
                    ans.push_back(to_string(start));
                }else{
                    a+=to_string(start);
                    a+="->";
                    a+=to_string(ind);
                    ans.push_back(a);
                    a="";
                }
                start=nums[i];
                ind=nums[i];
            }
        }
        if(start==ind){
                    ans.push_back(to_string(start));
                }else{
                    a+=to_string(start);
                    a+="->";
                    a+=to_string(ind);
                    ans.push_back(a);
                }
        return ans;
    }
};