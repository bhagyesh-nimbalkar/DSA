#include <bits/stdc++.h>
using namespace std;

void fillLPS(string& pat,int* lps)
{
     lps[0]=0;
     int len=0,i=1;
     while(i<pat.size())
     {
         if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
         }
         else {
             if(len==0){
                lps[i]=0;
                i++;
             }
             else len = lps[len-1]; 
         }
     }
}
void KMP(string& txt,string& pat)
{
     int n = txt.size();
     int m = pat.size();
     int lps[m];
     fillLPS(pat,lps);
     int i = 0,j=0;
     while(i<n)
     {
         if(txt[i]==pat[j]){ i++;j++;}
         if(j==m){ cout<<i-j<<' '; j = lps[j-1];}
         if(i<n && txt[i]!=pat[j])
         {
             if(j==0) i++;
             else j=lps[j-1];
         }
     }
     cout<<'\n';
}
int main(){ 
     string txt = "aabaabddes";
     string pat = "aab";
     KMP(txt,pat);
     return 0;
}