class Solution {
public:
    string f(string a, string b){
        string ans="";
        int i=0;
        int j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]==b[i]){
                ans+=a[i];
                i++;
                j++;
            }else{
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        string a=f(strs[0],strs[1]);
        for(int i=1;i<n;i++){
            if(!a.empty()){
                a=f(strs[i],a);
            }
        }
        return a;
    }
};