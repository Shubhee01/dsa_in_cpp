class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> m1;
        for(auto i:secret){
            m1[i]++;
        }
        map<int,int> m2;
        for(auto i:guess){
            m2[i]++;
        }
        int n=secret.length();
        int b=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                // cout<<i<<" "<<secret[i]<<endl;
                b++;
                m1[secret[i]]--;
                m2[secret[i]]--;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                if(m1.find(guess[i])!=m1.end() && m1[guess[i]]>0){
                    // cout<<m1[guess[i]]<<" "<<guess[i]<<endl;
                    c++;
                    m1[guess[i]]--;
                }
            }
        }
        // cout<<b<<" "<<c<<endl;
        string ans="";
        ans+=to_string(b);
        ans+="A";
        ans+=to_string(c);
        ans+="B";
        return ans;
    }
};