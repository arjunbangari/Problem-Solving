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

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        vector<ll> arr(n), brr(m);
        for(auto &u: arr)
            cin>>u;
        for(auto &u: brr)
            cin>>u;
        
        map<ll,ll> mp;
        for(auto u: arr)
            mp[u] = 1;
        
        ll flag = 1;
        for(auto u: brr){
            if(mp[u]){
                cout<<"YES"<<endl;
                cout<<1<<" "<<u<<endl;
                flag = 0;
                break;
            }
        }
        
        if(flag){
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}