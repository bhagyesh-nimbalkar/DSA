#include <bits/stdc++.h>
using namespace std;

void buildLPS(string text,vector<int>& lps)
{
     int len=0,i=1;
     lps[len]=0;
     while(i<text.size())
     {
         if(text[i]==text[len]){
            len++;
            lps[i]=len;
            i++;
         }
         else {
            if(len==0){
                lps[i]=0;
                i++;
            }else len = lps[len-1];
         }
     }
}
void KMP(string text,string pattern)
{
     vector<int> lps(pattern.size(),0);

}
int main(){
     string text="aababcdba";
     string pattern="abc";

     return 0;
}