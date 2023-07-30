class Solution {
public:
    int strangePrinterHelp(int l, int r, vector<vector<int>> &dp, string &s) {
        // if( l>r ) return 0;
        if( dp[l][r] != -1 ) return dp[l][r];

        int mini = INT_MAX, j = -1;
        for(int i=l; i<r; i++){
            if( s[i] != s[r] && j == -1 ) j = i;

            if( j != -1 ) 
                mini = min(mini, 1 + strangePrinterHelp(j, i, dp, s) + strangePrinterHelp(i+1, r, dp, s));
        }
        return dp[l][r] = mini == INT_MAX ? 0 : mini;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return strangePrinterHelp(0, n-1, dp, s) + 1;
    }
};