// first of all find the lcs and fill the dp table , now go with top down approach way of filling the data.. check at each instance whether the letters are
// same , if same then push back to the string , we do this until one of the string lengths become 0 
// then finally we reverse the string since we are storing the string in a top down manner we get the reversed string 
// So by reversing the string we get our required answer
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string str1 = "havoc";
    string str2 = "bhvct";
    int m = str1.size();
    int n = str2.size();
    // fill the dp table
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    int i = m, j = n;
    while(i > 0 && j > 0)
    {
        // If current character in both the strings are same, then current character is part of LCS
        if(str1[i - 1] == str2[j - 1])
        {
            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
        // If current character in X and Y are different & we are moving upwards
        else if(dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        // If current character in X and Y are different & we are moving leftwards
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}
