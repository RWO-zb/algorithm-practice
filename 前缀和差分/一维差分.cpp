#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx];
int b[maxx];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];//求差分
    }
    int l,r,c;
    while(m--){
        cin>>l>>r>>c;
        b[l]+=c;//对l到r的数据加c
        b[r+1]-=c;//补丁处理多加的
    }
    for(int i=1;i<=n;i++){//打印处理结果
        b[i]+=b[i-1];
        cout<<b[i]<<" ";
    }
    return 0;
}