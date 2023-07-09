class Solution {
public:


    int solve(string s)
    {
        int ans  = 0;

        for(char i ='a'; i<='z'; i++)
        {
            for(char j = 'a'; j<='z'; j++)
            {
                if(i!=j)
                {
                    int cnt1 = 0;
                    int cnt2 =0;
                    for(int k=0; k<s.size(); k++)
                    {
                        if(s[k]==i)
                        {
                            cnt1++;
                        }
                        if(s[k]==j)
                        {
                            cnt2++;
                        }
                        if(cnt2>cnt1)
                        {
                            cnt1 = 0;
                            cnt2 = 0;
                        }

                        if(cnt1>0 && cnt2>0)
                        {
                            ans = max(ans,cnt1-cnt2);
                        }
                    }
                    
                }
            }
        }

        return ans;
    }


    int largestVariance(string s) {
        int a  = solve(s);
        reverse(s.begin(),s.end());
        int b  = solve(s);

        return max(a,b);

    }
};