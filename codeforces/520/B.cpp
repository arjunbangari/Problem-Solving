#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    if(n>=m){
        cout<<n-m<<"\n";
    } else {
        ll level[20001];
        bool used[20001];
        memset(used,false,sizeof(used));
        memset(level,0,sizeof(level));
        queue<ll> q;
        q.push(n);
        level[n] = 0;
        used[n] = true;
        while(!q.empty()){
            ll temp = q.front();
            q.pop();
            if(temp==m)
                break;
            if(!used[temp-1] && (temp-1)>0){
                level[temp-1] = level[temp]+1;
                q.push(temp-1);
                used[temp-1] = true;
            }
            if((2*temp)<20001 && !used[2*temp]){
                level[2*temp] = level[temp]+1;
                q.push(2*temp);
                used[2*temp] = true;
            }
        }
        //for(ll i=0;i<20;i++)
        //    cout<<i<<" "<<level[i]<<"\n";
        cout<<level[m]<<"\n";
    }
    
    return 0;
}
