#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx][maxx]={0};
int dp[maxx][maxx]={0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin >> a[i][j];
    dp[1][1]=a[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];//状态转移方程
    int s=0;
    for(int i=1;i<=n;i++)
        if(dp[n][i]>s)
            s=dp[n][i];
    cout<<s<<endl;
}