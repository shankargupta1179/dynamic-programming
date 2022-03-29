// This problem is also a variation of the longest common subsequence lcs ...just find the similarity 
// in lcs we see the common part in both the strings give 
// but here we are given with only one string 
// and we need to find longest palindromic ...palindromic in the sense it should be same even when we reverse .. so we reverse the given string and find the lcs on
// those strings 

class Solution{
  public:
    int lcs(string a,string b , int n)
    {
        int dp[n+1][n+1];
        for(int i =0;i<n+1;i++)dp[i][0] = 0;
        for(int i =0;i<n+1;i++)dp[0][i] = 0;
        
        for(int i=1;i<n+1;i++)
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
        return dp[n][n];
    }
    int longestPalinSubseq(string a) {
        //code here
        string b = a;
        reverse(b.begin(),b.end());
        return lcs(a,b,a.size());
    }
};
