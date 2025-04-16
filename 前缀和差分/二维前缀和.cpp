#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx][maxx];
int sum[maxx][maxx];
int n,m,q;
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+sum[i-1][j]+a[i][j]-sum[i-1][j-1];
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<endl;
    }
}