#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> v[100005];
ll vis[100005];
ll color[100005];
ll flag = 0;

void dfs(ll i, ll clr){
    vis[i] = 1;
    color[i] = clr;
    for(ll u: v[i]){
        if(!vis[u])
            dfs(u, !clr);
        else if(color[u]==clr)
            flag = 1;
    }
}

int main(){
    fast;
    ll n,m,a,b;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            if(!v[i].empty()){
                dfs(i,0);
                if(flag){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    
    vector<ll> set1, set2;
    ll cnt1=0, cnt2=0;
    for(ll i=1;i<=n;i++){
        if(vis[i]){
            if(color[i]==0){
                set1.push_back(i);
                cnt1++;
            } else {
                set2.push_back(i);
                cnt2++;
            }
        }
    }
    
    cout<<cnt1<<endl;
    for(ll i : set1)
        cout<<i<<" ";
    cout<<endl<<cnt2<<endl;
    for(ll i: set2)
        cout<<i<<" ";
    
    return 0;
}