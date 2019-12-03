#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
vector<ll> v[100005];
ll n;

long double dfs(ll i, ll p){
    long double sum = 0;
    for(ll u: v[i])
        if(u!=p)
            sum+= dfs(u,i) + 1;
    return sum ? sum / (v[i].size() - (p != -1)) : 0;
}

int main(){
    fast;
    ll a,b;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<setprecision(6)<<fixed<<dfs(1,-1)<<"\n";
    
    return 0;
}