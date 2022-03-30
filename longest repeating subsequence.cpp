// just a small variation of longest common subsequence lcs
// just try to dry run the code so that ull get it 
class Solution {
	public:
		int LongestRepeatingSubsequence(string a){
		    // Code here
		    string b = a;
		    int n = a.size();
		    int dp[n+1][n+1];
		    
		    for(int i=0;i<n+1;i++)dp[i][0] = 0;
		    for(int i=0;i<n+1;i++)dp[0][i] = 0;
		    
		    for(int i=1;i<n+1;i++)
		    {
		        for(int j=1;j<n+1;j++)
		        {
		            if(a[i-1]==b[j-1] and i!=j)
		            {
		                dp[i][j] = 1+ dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};
