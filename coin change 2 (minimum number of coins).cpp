// Same as the maximum number of ways to give coin change , but a slight variation . Here we have to return the minimum number of coins that can be given as change
// first we fill every element in the dp matrix to INT MAX since we require the minimum coins that can be given as change , it would become handy to get the minimum
// time complexity is n**2 and space complexity is n**2 since we use an extra dp matrix 

class Solution{
	public:
	int findAns(int coins[],int m,int v,vector<vector<int>>&dp)
	{
	    if(m==0 && v>0)return INT_MAX-1;
        if(v==0)return 0;
	    
	    if(dp[v][m]!=INT_MAX-1)return dp[v][m];
	    
	    if(coins[m-1]<=v)
	    {
	        dp[v][m] = min(1+findAns(coins,m,v-coins[m-1],dp),findAns(coins,m-1,v,dp));
	        return dp[v][m];
	    }
	    else
	    {
	        dp[v][m] = findAns(coins,m-1,v,dp);
	        return dp[v][m];
	    }
	}
	int minCoins(int coins[], int M, int V) 
	{
	    vector<vector<int>> dp(V+1,vector<int>(M+1,INT_MAX-1));
	    
	    int ans = findAns(coins,M,V,dp);
	    if(ans==INT_MAX-1 || ans==INT_MAX) return -1;
	    return ans;
	} 
	  
};
