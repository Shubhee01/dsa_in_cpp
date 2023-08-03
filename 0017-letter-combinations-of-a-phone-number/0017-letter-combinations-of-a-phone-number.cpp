class Solution {
public:
    void f(int i,string s,map<char,string> &m,vector<string> &v,string digits){
        if(i==digits.length()){
            v.push_back(s);
        }
        for(int j=0;j<m[digits[i]].length();j++){
            string temp=s;
            s+=m[digits[i]][j];
            f(i+1,s,m,v,digits);
            s=temp;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.length()==0){
            return v;
        }
        map<char,string> m;
        m.insert({'2',"abc"});
        m.insert({'3',"def"});
        m.insert({'4',"ghi"});
        m.insert({'5',"jkl"});
        m.insert({'6',"mno"});
        m.insert({'7',"pqrs"});
        m.insert({'8',"tuv"});
        m.insert({'9',"wxyz"});
        f(0,"",m,v,digits);
        return v;
    }
};