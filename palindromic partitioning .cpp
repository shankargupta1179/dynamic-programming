// variation of an mcm problem 
// it seems little difficult , refer to aditya verma video to get a brief idea 
// we try to put a partition at every point and check whether all the substrings are going to form a palindrome or not
// and we take minimum partitions from all those 
// if the given string itself is a palindrome , we need not do any partitions // it means the number of min partitions is 0

class Solution{
public:
    int dp[501][501];
   bool ispalindrome(string &s, int i , int j){
       while(i<=j){
           if(s[i]==s[j]){
               i++;
               j--;
           }
           else{
               return false;
           }
       }
       return true;
   }
   int solve(string &s, int i, int j)
   {
       if (i >= j)
       {
           return dp[i][j] = 0;
       }
       if(ispalindrome(s,i,j)){
           return dp[i][j] = 0;
       }
       if (dp[i][j] != -1)
       {
           return dp[i][j];
       }
       dp[i][j] = INT_MAX;
       for (int k = i; k <= j-1; k++)
       {
           dp[i][j] = min(dp[i][j], solve(s, i, k) + solve(s, k + 1, j) + 1 );
       }
       return dp[i][j];
   }
   int palindromicPartition(string str)
   {
       memset(dp,-1,sizeof(dp));
       return solve(str,0,str.size()-1);
    }
};
