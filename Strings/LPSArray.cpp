#include <bits/stdc++.h>
using namespace std;

int main(){
    string str="AAABAAAAC";
    vector<int> lps(str.size(),0);
    int len = 0;
    for(int i=1;i<str.size();)
    {
         if(str[i]==str[len]){
            len++;
            lps[i]=len;
            i++;
         }
         else {
             if(len==0){
                lps[i]=0;
                i++;
             }
             else len = lps[i];
         }
    }
    for(int i=0;i<lps.size();i++) cout<<lps[i]<<' ';
    cout<<'\n';
    return 0;
}