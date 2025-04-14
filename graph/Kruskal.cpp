#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
int a[maxx][maxx];
struct edge{//边
    int begin;
    int end;
    int weight;
};
int n,m,sum=0;//n条边，m个顶点
edge edges[maxx];
int Find(int *parent,int f)//查找父节点
{
	while(parent[f]>0)
		f=parent[f];
	return f;
}
void Kruskal(){
    int b,e;
    int parent[n];
    for(int i=0;i<n;i++)parent[i]=0;
    for(int i=0;i<n;i++){
        b=Find(parent,edges[i].begin);//寻找第一个点的父节点
        e=Find(parent,edges[i].end);//寻找第二个点的父节点
        if(b!=e){//如果父节点不相同，说明存在点没有纳入
            parent[b]=e;//加入父节点
            printf("(%d,%d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);//打印边和权重
            sum+=edges[i].weight;
        }
    }
    cout<<sum<<endl;
}
int main() {
    cin >> m>>n;
    for(int i = 0; i < n; i++)
        cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
    sort(edges, edges + n, [](const edge &a, const edge &b) {
        return a.weight < b.weight;
    });
    Kruskal();
    return 0;
}