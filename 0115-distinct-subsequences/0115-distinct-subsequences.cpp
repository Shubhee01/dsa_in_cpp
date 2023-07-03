class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=f(i+1,j+1,s,t,dp)+f(i+1,j,s,t,dp);
        }
        return dp[i][j]=f(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,s,t,dp);
    }
};