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
        ll n;
        cin>>n;
        
        vector<ll> arr(2*n), cnt(2*n);
        for(auto &u: arr)
            cin>>u;
        
        for(auto u: arr){
            if(cnt[u])
                continue;
            cout<<u<<" ";
            cnt[u] = 1;
        }
        cout<<endl;
    }
    
    return 0;
}