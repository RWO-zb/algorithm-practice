#include<bits/stdc++.h>
using namespace std;
const int maxx=10000;
bool dp[maxx][maxx];
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int res=1,start=0,end=0;
    for(int i=0;i<s.length();i++)//初始化
        dp[i][i]=true;
    for(int i=1;i<s.length();i++){
        for(int j=0;j<i;j++){
            if(s[i]==s[j]){
                if(j+1==i){//两个相邻的相同则为回文
                    dp[j][i]=true;
                }
                else if(dp[j+1][i-1]){//对于一个字符两侧的字符相同且中间的字符为回文串则为回文
                    dp[j][i]=true;
                }
                if(dp[j][i]&&i-j+1>res){//记录最长回文子串
                    res=i-j+1;
                    start=j;
                    end=i+1;
                }
            }
        }
    }
    cout<<s.substr(start,end-start)<<endl;
}