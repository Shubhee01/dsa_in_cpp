class Solution {
public:
    long long f(int i,string s,int sign,long long res){
        if(res*sign>INT_MAX){
            return INT_MAX;
        }
        if(res*sign<INT_MIN){
            return INT_MIN;
        }
        if(i==s.length()){
            return res*sign;
        }
        if(s[i]<'0'|| s[i]>'9'){
            return res*sign;
        }
        return f(i+1,s,sign,(res*10)+(s[i]-'0'));
    }
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        return f(i,s,sign,0);
    }
};