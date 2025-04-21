#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int n,a[maxx];
//最长上升子序列
int lis1(){
    int result=0;
    int dp[maxx];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int t=0;
        for(int j=1;j<i;j++)
            if(dp[j]>t&&a[j]<a[i])//寻找子序列中最大上升序列
                t=dp[j];
        dp[i]=t+1;
        if(dp[i]>result)result=dp[i];//更新最大值
    }
    return result;
}
int LIS2(){//nlogn复杂度
    int len=1;
    int d[10010];
    d[1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>d[len])
            d[++len]=a[i];//比序列末尾等大则放到末尾
        else{
            int j=lower_bound(d+1,d+len+1,a[i])-d;//比尾更小则有序插入序列中
            d[j]=a[i];
        }
   }
    return len;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<LIS2()<<endl;
    }
    return 0;
}