#include<bits/stdc++.h>
using namespace std;
map<int ,int>mp;
int main(){
    int target,num;
    int *array=new int [num];
    cin>>target>>num;
    for(int i=0;i<num;i++)
        cin>>array[i];
    for(int i=0;i<num;i++){
        int a=target-array[i];
        if(mp.find(a)!=mp.end()){
            cout<<a<<"+"<<array[i]<<"="<<target<<endl;
            delete[]array;
            return 0;
        }
        mp[array[i]]=i;//存储下标，方便查找
    }
    delete[]array;
    return 0;
}
/*
    map的插入
    mp[a]=b
    map取值
    mp.at()
    map删除
    iterator erase( iterator pos )指向下一位置
    map查找
    mp.find(a)!=mp.end()
*/