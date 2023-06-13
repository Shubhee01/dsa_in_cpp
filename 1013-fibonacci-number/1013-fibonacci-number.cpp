class Solution {
public:
    int ans(int n){
        if(n==1 || n==0){
            return n;
        }
        return ans(n-1)+ans(n-2);
    }
    int fib(int n) {
        if(n==1 || n==0){
            return n;
        }
        return ans(n-1)+ans(n-2);
    }
};