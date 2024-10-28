#include <bits/stdc++.h>
using namespace std;

int climbingStairsmemo(int n){
	if(n==0) return 0;
	if (n==1) return 1;
	vector<int> dp(n,-1);
	for(int i = 2; i<n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}


int climbHelp(int n , vector<int> &dp) {
	if(n<=1) return 1;
	if(dp[n] != -1) return dp[n];
	dp[n] = climbHelp(n-1,dp) + climbHelp(n-2 , dp);
	return dp[n];
}

int climb(int n ) {
	vector<int> dp(n,-1);
	return climbHelp(n,dp);
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}