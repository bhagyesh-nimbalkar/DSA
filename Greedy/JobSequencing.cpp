#include <bits/stdc++.h>
using namespace std;

int MaxProfit(vector<pair<int,int>>& jobs)
{
     int profit=0;
     sort(jobs.begin(),jobs.end(),[](pair<int,int>& a,pair<int,int>& b){
        return a.first<b.first;
     });
     priority_queue<int> pq;
     int slots =0;
     for(int i=jobs.size()-1;i>=0;i--){
        if(i==0)
        { 
             slots=jobs[i].first;
        }
        else {
            slots = jobs[i].first-jobs[i-1].first;
        }
        pq.push(jobs[i].second);
        while(slots && !pq.empty()){
            slots--;
            profit+=pq.top();
            pq.pop();
        }
     }
     return profit;
}
int main(){
    vector<pair<int,int>> jobs{{3, 30}, {2, 50}, {1, 70}, {1, 100}};
    cout<<MaxProfit(jobs)<<'\n';
    return 0;
}