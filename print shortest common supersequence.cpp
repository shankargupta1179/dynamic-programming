// variation of lcs printing problem .. there we run the loop until one turns 0, because if one of the string length becomes 0 then lcs would be 0

// but in this case , we are not printing lcs , we want supersequence so we need to have all the characters even if one of the string goes zero
// observe the variation in the problem , it is not so hard

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = a.size();
        int n = b.size();
        int dp[m+1][n+1];
        for(int i =0;i<m+1;i++)dp[i][0] = 0;
        for(int i =0;i<n+1;i++)dp[0][i] = 0;
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
      int  i = m, j = n;
        string ans ="";
      while(i>0 and j>0)
      {
          if(a[i-1]==b[j-1])
          {
              ans.push_back(a[i-1]);
              i--;
              j--;
          }
          else if(dp[i][j-1]>dp[i-1][j])
          {
              
                ans.push_back(b[j-1]);
                j--;
          }
          else 
          {
              ans.push_back(a[i-1]);
              i--;
          }
      }
        while(i>0)
        {
            ans.push_back(a[i-1]);
            i--;
        }
        while(j>0)
        {
            ans.push_back(b[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
