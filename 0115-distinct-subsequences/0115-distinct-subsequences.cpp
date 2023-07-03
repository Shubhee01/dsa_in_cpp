class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
        }
        return dp[i][j]=f(i-1,j,s1,s2,dp);
    }
    int mod=1e9+7;
    int f2(int i, int j, string &s1, string &s2){
        vector<vector<int>> dp(i+1,vector<int>(j+1,0));
        for(int a=0;a<=i;a++){
            dp[a][0]=1;
        }
        for(int a=1;a<=i;a++){
            for(int b=1;b<=j;b++){
                if(s1[a-1]==s2[b-1]){
                    dp[a][b]=(dp[a-1][b-1]+dp[a-1][b])%mod;
                }else{
                    dp[a][b]=dp[a-1][b]%mod;
                }
            }
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(n-1,m-1,s,t,dp);
        return f2(n,m,s,t);
        
    }
};