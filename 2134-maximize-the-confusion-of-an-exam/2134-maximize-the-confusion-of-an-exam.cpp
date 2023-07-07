class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int n=a.size();
        map<char,int> m;
        int j=0;
        int count=0;
        int mini=0;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            mini=min(m['T'],m['F']);
            while(mini>k){
                m[a[j]]--;
                j++;
                mini=min(m['T'],m['F']);
            }
            count=max(count,i-j+1);
        }
        return count;
    }
};