#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int dp[maxx][maxx];
string s1,s2;
//最长公共子序列
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;//若相等则加一
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//不相等则继承上侧或左侧中的最大值
        }
    }
    cout<<dp[s1.length()][s2.length()]<<endl;
    return 0;
}