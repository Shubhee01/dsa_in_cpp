class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> m1;
        for(auto i:secret){
            m1[i]++;
        }
        int n=secret.length();
        int b=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                b++;
                m1[secret[i]]--;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                if(m1.find(guess[i])!=m1.end() && m1[guess[i]]>0){
                    c++;
                    m1[guess[i]]--;
                }
            }
        }
        string ans="";
        ans+=to_string(b);
        ans+="A";
        ans+=to_string(c);
        ans+="B";
        return ans;
    }
};