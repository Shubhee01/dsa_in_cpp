class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int n=s.length();
        int prev=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(count==0){
                    continue;
                }
                prev=count;
                count=0;
            }
            else{
                count++;
            }
        }
        if(count==0){
            return prev;
        }
        return count;
    }
};