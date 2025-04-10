#include<bits/stdc++.h>
using namespace std;
const int maxx =10000;
int n;
int a[maxx];
bool f[maxx];
//dfs模板，求全排列
void dfs(int u){
    if(u==n){//判断是否满足终止条件
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return;        
    }
    for(int i=1;i<=n;i++){//循环开始遍历
        if(f[i]==false){//没被访问则访问
            f[i]=true;
            a[u]=i;//访问处理
            dfs(u+1);//搜索下一个
            a[u]=0;//复原处理
            f[i]=false;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}