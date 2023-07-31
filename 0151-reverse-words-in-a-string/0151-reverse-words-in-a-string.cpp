class Solution {
public:
    string reverseWords(string s) {
        string a="";
        int n=s.length();
        vector<string> v;
        for(int i=0;i<n;i++){
            if(s[i]==' ' && !a.empty()){
                // cout<<"wow"<<endl;
                v.push_back(a);
                a="";
                continue;
            }else if(s[i]!=' '){
                // cout<<s[i]<<endl;
                a+=s[i];
            }
        }
        // cout<<"aaaa"<<a<<"aaaa"<<endl;
        if(a!=""){
            v.push_back(a);
        }
        a="";
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            a+=v[i];
            if(i!=v.size()-1){
                a+=" ";
            }
            // cout<<v[i]<<endl;
        }
        return a;
    }
};