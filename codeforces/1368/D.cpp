#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<ll> cnt(30);
    
    for(auto u: arr){
        for(ll i=0;i<=20;i++){
            if(1&u)
                cnt[i]++;
            u = u>>1;
        }
    }
    
    ll ans = 0;
    
    while(1){
        ll tmp = 0;
        for(ll i=0;i<=20;i++){
            if(cnt[i]){
                tmp += 1<<i;
                cnt[i]--;
            }
        }
        if(tmp)
            ans += tmp*tmp;
        else
            break;
    }
    
    cout<<ans<<endl;
    
    return 0;
}