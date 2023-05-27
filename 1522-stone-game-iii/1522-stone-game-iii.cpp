class Solution {
public:
   vector<int>prefix;
   int fun(int i,vector<int>&stone,vector<int>&dp)
   {
       if(i==stone.size())return  0;
       if(dp[i]!=INT_MIN)return dp[i];
       int n=stone.size();
       int sum=0;
       int val=-1e9;
      for(int x=i;x<=min(i+2,n-1);x++)
      {
          sum+=stone[x];
          val=max(val,sum+fun(x+1,stone,dp));
      }
      return  dp[i]=prefix[i]-val;
   }
    string stoneGameIII(vector<int>& stone) {int n=stone.size();
        prefix.resize(n,0);
         vector<int>dp(n+1,INT_MIN);
         prefix[n-1]=stone[n-1];
         for(int i=n-2;i>=0;i--)
         {
             prefix[i]=prefix[i+1] + stone[i];
         }
          int val=fun(0,stone,dp); // this for bob
          cout<<val;
          if(val>prefix[0]-val)return "Bob";
          if(val<prefix[0]-val)return "Alice";
          return "Tie";
          
          
        
    }
};