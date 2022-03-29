// these problems follow the same pattern 
// it is similar to problem where we convert a string a to string b 
// but here we have to convert it to longest palindromic sentence
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
int minDeletions(string a, int n) { 
    //complete the function here 
        string b = a;
        reverse(b.begin(),b.end());
        return n - lcs(a,b,n);
} 
