#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[300], vis(300), color(300);
ll cycle = 0;

void dfs(ll i, ll p=-1, ll c=0){
    vis[i] = 1;
    color[i] = c;
    for(auto u: v[i]){
        if(u==p)
            continue;
        if(vis[u]){
            if(color[u]==c){
                cycle = 1;
                return;
            } 
            continue;
        }
        dfs(u, i, !c);
    }
}


int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++){
            if(s[j]>s[i]){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    if(cycle){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        for(ll i=0;i<n;i++)
            cout<<color[i];
    }
    
    return 0;
}