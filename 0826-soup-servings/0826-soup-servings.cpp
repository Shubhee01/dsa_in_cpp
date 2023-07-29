class Solution {
public:
    double f(int a, int b, vector<vector<double>> &dp){
        if(a<=0 && b<=0){
            return (double)1/2;
        }
        if(a<=0 && b>0){
            return 1;
        }
        if(a>0 && b<=0){
            return 0;
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        double o1=f(a-100,b-0,dp);
        double o2=f(a-75,b-25,dp);
        double o3=f(a-50,b-50,dp);
        double o4=f(a-25,b-75,dp);
        return dp[a][b]=(double)(o1+o2+o3+o4)/(double)4;
    }
    double soupServings(int n) {
        if(n>=4800){
            return 1;
        }
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1)); 
        double ans=f(n,n,dp);
        return ans;
    }
};