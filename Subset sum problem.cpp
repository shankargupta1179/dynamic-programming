// This problem is a variation of the standard problem known as 0-1 knapsack problem , In that problem we have to choose the items in such a way that the profit is maximised 
// In this case we have to choose the numbers in such a way that it becomes equal to the target given in the question
// Only Recursion - Time complexity - exponential 2^n . This contains repetitive calls which leads to the exponential time complextiy
// recursion + memoization - Time complexity - n^2 . We take a matrix and store the values of each call , when a same call is occured again , we just return it and not calculate 
// it again.
// Problem link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#
class Solution{   
public:
      int dp[101][10001];
      bool solve(int N,int arr[],int sum)
      {
          if(sum==0)return true;
          if(N<0)return false;
          
        if(dp[N][sum] != -1){
            return dp[N][sum];
        }
        if(arr[N-1]<=sum)
        {
            dp[N][sum]= (solve(N-1,arr,sum-arr[N-1])|| solve(N-1,arr,sum));
        }
        
        else if(arr[N-1]>sum) dp[N][sum]= solve(N-1,arr,sum);
        
        return dp[N][sum];
      }
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
       memset(dp,-1,sizeof(dp));
        return solve(N,arr,sum);
    }
};
