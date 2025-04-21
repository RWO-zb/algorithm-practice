#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx]={0};
int dp[maxx]={0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,s=INT_MIN;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        if(dp[i-1]>0)//前期状态大于零则相加
            dp[i]=dp[i-1]+a[i];//状态转移方程
        else
            dp[i]=a[i];//小于零则不可能更大，于是重新开始计算
        if(s<dp[i])
            s=dp[i];
    }
    cout<<s<<endl;
}