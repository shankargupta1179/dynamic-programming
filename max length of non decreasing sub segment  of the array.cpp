// problem link https://codeforces.com/problemset/problem/580/A
// this is an easy problem , we have to check whether the previous number is less than or equal to the current number , if it is true , we will increment the size of the longest
// segment else we will make the segment length to one, but before this we store the max of the both k and ans
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n ;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k = 1;
	int ans = INT_MIN;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>=arr[i-1])k++;
		else
		{
		 ans = max(ans,k);
		 k=1;
	    }
	    
	}
	ans = max(ans,k);
	cout<<ans<<endl;
}
