// think in a step wise way , first how to make string a to lcs and how to make lcs to string b ... to make string a to lcs we have to delete some of the letters 
// to make lcs to string b we have to add some letters 
// so we got number of insertions and also deletions 
// now we can add insertions and deletions to get the answer

class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    int dp[m+1][n+1];
	    for(int i=0;i<m+1;i++)dp[i][0]=0;
	    for(int i=0;i<n+1;i++)dp[0][i]=0;
	    
	    for(int i=1;i<m+1;i++)
	    {
	        for(int j=1;j<n+1;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return (m-dp[m][n]) + (n-dp[m][n]);
	} 
};
