class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 || k==1) return 0;
        int parent=kthGrammar(n-1,(k+1)/2);
        if(k%2==0){
            return parent==1?0:1;
        }else{
            return parent;
        }
    }
};
// 0 1,1
// 01 2,2
// 0110 3,4
// 01101001 4,8
// 0110100110010110 5,16
// 01101001100101101001011001101001 6,32