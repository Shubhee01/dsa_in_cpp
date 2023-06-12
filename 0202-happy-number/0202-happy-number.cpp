class Solution {
public:
    int ans(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=pow(rem,2);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int,int> m;
        while(m[n]!=2){
            m[n=ans(n)]++;
            cout<<n<<endl;
            if(n==1){
                return true;
            }
        }
        return false;
    }
};