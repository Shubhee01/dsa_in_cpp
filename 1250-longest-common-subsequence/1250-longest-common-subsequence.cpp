class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>> &dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        int nottake=max(f(i+1,j,s1,s2,dp),f(i,j+1,s1,s2,dp));
        if(s1[i]==s2[j]){
            take=1+f(i+1,j+1,s1,s2,dp);
        }
        return dp[i][j]=max(take,nottake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,text1,text2,dp);
    }
};