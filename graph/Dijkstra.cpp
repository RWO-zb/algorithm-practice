#include<bits/stdc++.h>
using namespace std;
int n,m;//n个顶点m条边
const int maxx=10000;
bool vis[maxx];
int dis[maxx];
int a[maxx][maxx];
void dijkstra(){
    memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    int u=0;
    for(int i=1;i<=n;i++){
        int mymin=maxx;
        for(int j=1;j<=n;j++)
            if(dis[j]<mymin&&!vis[j]){
                mymin=dis[j];
                u=j;
            }
        vis[u]=true;
        for(int j=1;j<=n;j++){
            if(vis[j]==false&&dis[j]>dis[u]+a[u][j])
                dis[j]=dis[u]+a[u][j];
        }
    }
}
int main() {
    cout << "m,m ";
    cin >> n >> m;

    // 初始化邻接矩阵
    memset(a, 0x3f, sizeof(a));
    cout << "m" << m  << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<endl;
    return 0;
}
