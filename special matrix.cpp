//This is a dp problem ,it can be easily identified as a dp problem by looking at the question which asks the number of ways from a particular point to end 
// this itself says that it need to store the number of ways from a particular point to reach the end 
// Recursive approach can be derived easily, from there we could optimise it using a dp array which helps us to avoid the redundant recursive calls that helps to reduce time 
// complexity
// Problem Link - https://practice.geeksforgeeks.org/problems/special-matrix4201/1#
class Solution {
public:
    int mod = (int)1e9+7;
    int dp[501][501];
    int helper(int n, int m, set<pair<int,int>>&st,int i,int j)
    {
        if(i>n || j>m || st.count({i,j})>0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n and j==m)return 1;
        int right =helper(n,m,st,i,j+1); 
        int down =  helper(n,m,st,i+1,j);
        return dp[i][j] = (right+down)%mod;
    }
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    set<pair<int,int>>st;
	    memset(dp,-1,sizeof(dp));
	    for(auto it:blocked_cells){
           int x=it[0];
           int y=it[1];
           st.insert({x,y});
        }
	    return helper(n,m,st,1,1);
	}
};
