class Solution {
public:
    long long f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0 && j<0){
            return 0;
        }
        long long take=1e9;
        if(i<0){
            take=0;
            while(j>=0){
                take+=s2[j];
                j--;
            }
            return take;
        }
        if(j<0){
            take=0;
            while(i>=0){
                take+=s1[i];
                i--;
            }
            return take;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long nottake2=(int)s1[i]+f(i-1,j,s1,s2,dp);
        long long nottake1=(int)s2[j]+f(i,j-1,s1,s2,dp);
        if(s1[i]==s2[j]){
            take=f(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=min(take,min(nottake2,nottake1));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
};