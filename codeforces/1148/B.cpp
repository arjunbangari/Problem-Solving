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
    
    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    
    vector<ll> arr(n), brr(m);
    for(auto &u: arr)
        cin>>u;
    for(auto &u: brr)
        cin>>u;
        
    ll ans = -1;
    
    if(k>=n){
        cout<<-1<<endl;
        return 0;
    }
    
    for(ll i=0;i<=k && i<n;i++){
        auto it = lower_bound(brr.begin(), brr.end(), arr[i]+ta) - brr.begin();
        it += (k-i);
        if(it>=m){
            cout<<-1<<endl;
            return 0;
        }
        ans = max(ans, brr[it]+tb);
    }
    
    cout<<ans<<endl;
    
    return 0;
}