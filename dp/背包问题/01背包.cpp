#include<bits/stdc++.h>
using namespace std;
int w[105],val[105],dp[1005];
int main(){
    int t,m;
    cin>>t>>m;
    for(int i=0;i<m;i++)
        cin>>w[i]>>val[i];
    for(int i=0;i<m;i++){
        for(int j=t;j>=0;j--)//倒序，因为需要前面的数据
            if(j>=w[i])
                dp[j]=max(dp[j-w[i]]+val[i],dp[j]);//计算装物体和不装谁更大
    }
    cout<<dp[t]<<endl;
    return 0;
}