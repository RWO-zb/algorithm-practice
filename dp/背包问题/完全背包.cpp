#include<bits/stdc++.h>
using namespace std;
const int maxx=1000;
int w[maxx],v[maxx],dp[maxx];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(j>=w[i])
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    cout<<dp[m]<<endl;
    return 0;
}