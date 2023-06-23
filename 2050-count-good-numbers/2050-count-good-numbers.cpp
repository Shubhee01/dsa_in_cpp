class Solution {
public:
    int N=1e9+7;
    long long power(long long a, long long n){
        long long ans=1;
        while(n>0){
            int last_bit=(n&1);
            if (last_bit) {
                ans=((long long)ans*(long long)a)%N;
            }
            a=((long long)a*(long long)a)%N;
            n=n>>1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;
        return (power(5,even)*power(4,odd))%N;
    }
};