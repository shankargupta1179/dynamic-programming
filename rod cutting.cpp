// This problem is same as unbounded knapsack, price is being provided and sometimes length array is also provided else we can generate it 
// Nothing much to say about this , the time complexity is n**2 and also the space complexity is n**2 since we take a matrix to store the value of queries 
// so that when they appear again we make sure that we dont further calculate it again which saves a lot of time .. Due to this particular memoization
// the time complexity drops down from 2**n to n**2 
class Solution{
  public:
    int findAns(int price[],int length[],vector<vector<int>>&dp,int n,int l)
    {
        if(n<=0 || l<=0)return 0;
        
        if(dp[n][l]!=-1)return dp[n][l];
        
        if(length[n-1]<=l)
        {
            dp[n][l] = max(price[n-1]+findAns(price,length,dp,n,l-length[n-1]),findAns(price,length,dp,n-1,l));
            return dp[n][l];
        }
        else if(length[n-1]>l)
        {
            dp[n][l] = findAns(price,length,dp,n-1,l);
            return dp[n][l];
        }
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n+1;i++)
        dp[i][0]=0;
        
        for(int j=0;j<n+1;j++)
        dp[0][j] = 0;
        
        int length[n]={0};
        for(int i=1;i<n+1;i++)
        {
            length[i-1] = i;
        }
        int l = n;
        return findAns(price,length,dp,n,l);
    }
};
