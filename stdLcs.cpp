#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
static bool comp(string &a , string &b)
{
	return a.size()<b.size();
}

int f(int i, int j, string s1, string s2, vector<vector<int> > &dp)
{
    if(i<0 or j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
    return dp[i][j]=max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
}

int lcs(int x, int y, string s1, string s2)
{
	//Takes auxilary stack space but reduces the time complexity which was initially exponential.
    vector<vector<int> > dp(x, vector<int>(y, -1));
	return f(x-1, y-1, s1, s2, dp);

    // vector<vector<int>> dp(x+1, vector<int>(y+1, 0));  Using two loops and a 2d array

	//This approach (space optimized) takes no recursion stack space and has a space complexity of O(y+1) and TC is around O(x*y)

    // vector<int> prev(y+1,0), curr(y+1, 0);
    // for(int i=0; i<=y; i++)
    // {
    //     prev[i]=0;
    // }
    // for(int i=1; i<=x; i++)
    // {
    //     for(int j=1; j<=y; j++)
    //     {
    //         if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
    //         else curr[j]=max(prev[j], curr[j-1]);  
    //     }
    //     prev=curr;
    // }
    // return prev[y];
}
int main()
{
	string s1, s2;
	cin>>s1>>s2;
	int x = s1.length();
	int y = s2.length();
	int val = lcs(x, y, s1, s2);
	cout<<val<<endl;
	return 0;
}