#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[100005];
map<pair<ll,ll>,ll> fault;
unordered_set<ll> us;

ll dfs(ll i, ll p){
    ll  ans = 0;
    for(ll u: v[i]){
        if(u!=p){
            ll check = dfs(u,i);
            ans = ans | check;
        }
    }
    if(ans)
        return 1;
    else if(fault[{i,p}]){
        us.insert(i);
        return 1;
    } else 
        return 0;
}

int main(){
    fast;
    
    ll n,x,y,t;
    cin>>n;
    
    for(ll i=0;i<n-1;i++){
        cin>>x>>y>>t;
        v[x].push_back(y);
        v[y].push_back(x);
        if(t==2){
            fault[{x,y}] = 1;
            fault[{y,x}] = 1;
        }
    }
    
    dfs(1,1);
    
    ll sz = us.size();
    cout<<sz<<endl;
    
    for(auto u: us)
        cout<<u<<" ";
    
    return 0;
}