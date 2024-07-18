class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        int i=1;
        string ans="";
        for(auto a:s){
            m[a]++;
        }
        for(auto a:order){
            if(m.find(a)!=m.end()){
                while(m[a]>0){
                    ans+=a;
                    m[a]--;
                }
            }
        }
        for(auto a:m){
            while(a.second>0){
                ans+=a.first;
                a.second--;
            }
        }
        return ans;
    }
};