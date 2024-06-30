class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.length();i++){
            int val=abs(s[i]-s[i-1]);
            ans+=val;
        }
        return ans;
    }
};