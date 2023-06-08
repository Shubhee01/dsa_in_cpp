class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0 || right==0){
            return 0;
        }
        int lp=(int)log2(left);
        if(left==right){
            return left;
        }
        if(pow(2,lp+1)<=right){
            return 0;
        }
        long long sum=left;
        for(long long i=left+1;i<=right;i++){
            sum=sum&i;
        }
        return sum;
    }
};