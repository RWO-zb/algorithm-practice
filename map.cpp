#include<bits/stdc++.h>
using namespace std;
map<int ,int>mp;
int main(){
    int target,num;
    int *array=new int [num];
    cin>>target>>num;
    for(int i=0;i<num;i++)
     cin>>array[i];
    mp.insert(pair(array[0],target-array[0]));
    for(int i=0;i<num;i++){
        int a=target-array[i];
        if(mp.find(a)!=mp.end()){
            cout<<a<<"+"<<array[i]<<"="<<target<<endl;
            delete[]array;
            return 0;
        }
        mp[array[i]]=i;  
    }
    delete[]array;
    return 0;
}