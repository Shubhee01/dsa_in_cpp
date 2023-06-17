int dp[2][2000]{}; //[steps][index];

class Solution {
public:
    // @dwsyip
    inline __attribute((always_inline)) int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        vector<int> arr1 {move(a)};
        vector<int> arr2 {move(b)};
        sort(arr2.begin(), arr2.end());

        int n1 = arr1.size();
        int n2 = arr2.size();
        int ub {};
        int idx {};
        auto it = arr2.begin();

        fill_n(&dp[0][0], n1, INT_MAX);
        fill_n(&dp[1][0], n1, INT_MAX);

        dp[0][0] = arr1[0];
        for(int i = 1; i < n1; ++i) {
            if (dp[0][i-1] >= arr1[i]) break;
            dp[0][i] = arr1[i];
        }
        dp[1][0] = min(arr1[0], *arr2.begin());

        for(int step{1}; step <= n2; ++step) {
            #define prev (step^1)&1
            #define curr step&1
            if (step > 1) dp[curr][step-1] = dp[prev][step-1]; 
            it = arr2.begin();
            for(idx = max(1, step-1); idx < n1; ++idx) {
                ub = INT_MAX;
                it = upper_bound(it, arr2.end(), dp[prev][idx-1]);  
                if (it != arr2.end()) ub = min(*it, ub); 
                if (arr1[idx] > dp[curr][idx-1]) ub = min(arr1[idx], ub); 
                if (ub == INT_MAX) break; 
                dp[curr][idx] = ub;
            }
            if (dp[curr][n1-1] < INT_MAX) return step;
        }
        return -1;
    }
};