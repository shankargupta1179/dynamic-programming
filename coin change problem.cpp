// problem link https://practice.geeksforgeeks.org/problems/coin-change2448/1#

// This problem is same as unbounded knapsack , given that infinite number of coins of each type are present which says that we can use a single coin as many
// times as we want i.e it is indirectly said that it is unbounded knapsack problem

// similar complexity n**2 time and n**2 space

class Solution {
  public:
    long long int findAns(int s[],int m ,int n ,vector<vector<long long>> &dp )
    {
        if(m<0)return 0;
        if(n==0)return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[m-1]<=n)
        {
            dp[n][m] = findAns(s,m,n-s[m-1],dp) + findAns(s,m-1,n,dp);
            return dp[n][m];
        }
        else
        {
            dp[n][m] = findAns(s,m-1,n,dp);
            return dp[n][m];
        }
    }
    long long int count(int S[], int m, int n) {
        
        vector<vector<long long int>> dp(n+1,vector<long long int >(m+1,-1));
        for(int i=0;i<n+1;i++)dp[i][0] = 0;
        for(int i=0;i<m+1;i++)dp[0][i] = 0;
        
        return findAns(S,m,n,dp);
    }
};
