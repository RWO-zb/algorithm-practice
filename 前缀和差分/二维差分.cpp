#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx][maxx]={0};
int b[maxx][maxx]={0};
void insert(int x1,int y1,int x2,int y2,int c){//对指定区域进行处理
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)//求差分
        for(int j=1;j<=m;j++)
            b[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
    while(q--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }
    for(int i=1;i<=n;i++)//求前缀和复原原矩阵
        for(int j=1;j<=m;j++)
            b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0; 
}