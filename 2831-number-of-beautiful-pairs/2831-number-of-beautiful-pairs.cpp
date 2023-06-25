#include <bits/stdc++.h>
class Solution {
public:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);   
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                string a=to_string(nums[i]);
                string b=to_string(nums[j]);
                int a1=int(a[0])-int('0');
                int b1=int(b[b.length()-1])-int('0');
                if(gcd(a1,b1)==1){
                    count++;
                }
            }
        }
        return count;
    }
};