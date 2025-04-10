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
    dis[1]=0;//从第一个点开始
    int u=0;
    for(int i=1;i<=n;i++){
        int mymin=0x3f;
        for(int k=1;k<=n;k++){//寻找当前没有被访问的距离最小的点
            if(!vis[k]&&dis[k]<mymin){
                mymin=dis[k];
                u=k;
            }
        }
        vis[u]=true;
        for(int k=1;k<=n;k++){//更新当前的距离状态
            if(!vis[k]&&dis[k]>dis[u]+a[u][k])
                dis[k]=dis[u]+a[u][k];
        }
    }
}
int main() {
    cin >> n >> m;
    memset(a, 0x3f, sizeof(a));
    for (int i = 0; i < m; i++) {//输入m条边
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    dijkstra();
    for(int i=1;i<=n;i++)//输出结果
        cout<<dis[i]<<endl;
    return 0;
}
