class Solution {
public:
    bool f2(string a, string b){
        int i=0;
        int j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(j==b.length()){
            return true;
        }
        return false;
    }
    int f(string s, map<int,vector<string>>& m, map<string,int>& m2){
        int n=s.length();
        if(m.find(n+1)==m.end()){
            // cout<<n+1<<"hello";
            return 1;
        }
        if(m2.find(s)!=m2.end()){
            return m2[s];
        }
        vector<string> v=m[n+1];
        int count=1;
        for(int i=0;i<v.size();i++){
            // cout<<v[i]<<" "<<s<<endl;
            if(f2(v[i],s)){
                // cout<<count<<" "<<v[i]<<endl;
                count=max(count,1+f(v[i],m,m2));
            }
        }
        return m2[s]=count;
    }
    int longestStrChain(vector<string>& words) {
        map<int,vector<string>> m;
        int n=words.size();
        for(int i=0;i<n;i++){
            m[words[i].length()].push_back(words[i]);
        }
        int maxi=1;
        map<string,int> m2;
        for(int i=0;i<n;i++){
            maxi=max(maxi,f(words[i],m,m2));
        }
        return maxi;
    }
};