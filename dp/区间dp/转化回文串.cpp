#include<bits/stdc++.h>
using namespace std;
int w[30],n,m,dp[2005][2005];
char s[2005],ch;
int main(){
    int x,y;
    while(cin>>n>>m){
        cin>>s;
        for(int i=0;i<n;i++){
            cin>>ch>>x>>y;
            w[ch-'a']=min(x,y);
        }
        for(int i=m-1;i>=0;i--){//从最后开始，因为dp区间是左上角
            for(int j=i+1;j<m;j++){
                if(s[i]==s[j])//相等则不用修改继承子区间费用
                    dp[i][j]=dp[i+1][j-1];
                else
                    dp[i][j]=min(dp[i+1][j]+w[s[i]-'a'],dp[i][j-1]+w[s[j]-'a']);//不相等则修改费用较小的一侧
            }
        }
        cout<<dp[0][m-1];
    }
    return 0;
}