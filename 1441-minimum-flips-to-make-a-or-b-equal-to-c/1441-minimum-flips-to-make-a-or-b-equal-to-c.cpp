class Solution {
public:
    int bit(int n){
        int x=n&1;
        if(x>=1){
            return 1;
        }else{
            return 0;
        }
    }
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a>0 || b>0 || c>0){
            int a1=bit(a);
            int b1=bit(b);
            int c1=bit(c);
            // cout<<a1<<" "<<b1<<" "<<c1<<endl;
            if(c1==1){
                if(a1==0 && b1==0){
                    count++;
                }
            }else{
                if(a1==1 && b1==1){
                    count+=2;
                }else if(a1==1 || b1==1){
                    count++;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;    
    }
};