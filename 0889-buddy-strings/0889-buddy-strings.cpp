class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        int val=0;
        map<int,int> m1;
        map<int,int> m2;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                val++;
            }
            m1[s[i]]++;
            m2[goal[i]]++;
        }
        if(val==2 && m1==m2){
            return true;
        }
        if(s==goal && m1.size()<s.length()){
            return true;
        }
        return false;
    }
};