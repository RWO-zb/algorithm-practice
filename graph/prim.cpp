#include<bits/stdc++.h>
using namespace std;
int n,m;//n个顶点m条边
const int maxx=10000;
bool vis[maxx];
int dis[maxx];
int a[maxx][maxx];
//将已连接的点视为一个整体，运用Dijkstra算法
int prim(){//最小生成树
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[1]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int u=-1;//u==-1来处理第一个点
        for(int j=1;j<=n;j++)//寻找当前未连接的点里最小的边
            if(!vis[j]&&(u==-1||dis[j]<dis[u]))
                u=j;
        vis[u]=1;
        ans+=dis[u];//求和
        for(int j=1;j<=n;j++)//加入新点后，更新当前已连接点到未连接的点的最短距离
            if(!vis[j]&&dis[j]>a[u][j])
                dis[j]=a[u][j];
    }
    return ans;
}
int main() {
    n = 5; // 5个顶点
    m = 7; // 7条边
    // 初始化邻接矩阵，初始值为INT_MAX表示不可达
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = INT_MAX;
        }
    }
    // 添加边及其权重（无向图）
    a[1][2] = a[2][1] = 2;
    a[1][3] = a[3][1] = 4;
    a[2][3] = a[3][2] = 1;
    a[2][4] = a[4][2] = 3;
    a[3][4] = a[4][3] = 2;
    a[3][5] = a[5][3] = 5;
    a[4][5] = a[5][4] = 1;
    int result = prim();
    cout << "Minimum Spanning Tree Weight: " << result << endl;
    return 0;
}