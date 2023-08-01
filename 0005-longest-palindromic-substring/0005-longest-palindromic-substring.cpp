class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1){
            return s;
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int maxi=1;
        int a=0;
        for(int k=1;k<n;k++){
            int i=0;
            for(int j=0;j<n-k;j++){
                // cout<<s[i]<<" "<<s[j+k]<<endl;
                if(k==1){
                    if(s[i]==s[j+k]){
                        dp[i][j+k]=1;
                        maxi=max(maxi,j+k-i+1);
                        a=i;
                    }
                }else{
                    if(s[i]==s[j+k] && dp[i+1][j+k-1]==1){
                        dp[i][j+k]=1;
                        maxi=max(maxi,j+k-i+1);
                        a=i;
                    }
                }
                i++;
            }
        }  
        return s.substr(a,maxi);
    }
};