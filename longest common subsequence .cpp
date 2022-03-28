// This is top down approach of longest common subsequence
// The time complexity is m*n where m is the length of first and n is the length of second string 
// The space complexity is m*n , since we create a matrix of size of m*n to store the values , so that we do not recompute the values which saves our time
// This is also known as memoization + recursion

class Solution
{
    public:
    int dp[1001][1001];
    
    //Function to find the length of longest common subsequence in two strings.
    int solve(int x, int y, string s1, string s2)
    {
        // your code here
        if(x==0 || y==0)return 0;
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        if(s1[x-1]==s2[y-1])
        {
            dp[x][y] = 1 + solve(x-1,y-1,s1,s2); // if both letters are same , then we move both the strings 
            return dp[x][y];
        }
        else
        {
            dp[x][y] = max(solve(x,y-1,s1,s2),solve(x-1,y,s1,s2)); // if both letters are not same , we have two conditions to check and we select the max.since it 
          // longest common subsequence
            return dp[x][y];
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        memset(dp,-1,sizeof(dp));
        return solve(x,y,s1,s2);
    }
    
};
