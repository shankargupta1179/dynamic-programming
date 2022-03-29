class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int LCS(string a,string b,int m,int n)
    {
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)dp[i][0] = 0;
        for(int i=0;i<n+1;i++)dp[0][i] = 0;
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        return m+n-LCS(X,Y,m,n);
    }
};
