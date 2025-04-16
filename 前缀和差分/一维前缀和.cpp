#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx];
int sum[maxx]={0};
int main(){
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
}