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

    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<ll> presum(n), sufsum(n), pre(n), suf(n), preind(n), sufind(n);
    
    for(ll i=0;i<n;i++){
        presum[i] = arr[i];
        if(i!=0)
            presum[i] += presum[i-1];
    }
    
    for(ll i=n-1;i>=0;i--){
        sufsum[i] = arr[i];
        if(i!=(n-1))
            sufsum[i] += sufsum[i+1];
    }
    
    pre[k-1] = presum[k-1];
    preind[k-1] = 0;
    
    for(ll i=k;i<n;i++){
        pre[i] = presum[i] - presum[i-k];
        preind[i] = ( pre[i]>=pre[i-1] ? i-k+1 : preind[i-1] );
        pre[i] = max(pre[i], pre[i-1]);
    }
    
    suf[n-k] = sufsum[n-k];
    sufind[n-k] = n-k;
    
    for(ll i=(n-k-1);i>=0;i--){
        suf[i] = sufsum[i] - sufsum[i+k];
        sufind[i] = ( suf[i]>=suf[i+1] ? i : sufind[i+1] );
        suf[i] = max(suf[i], suf[i+1]);
    }
    
    ll mx = -1, l , r;
    
    for(ll i=k-1;i<(n-k);i++){
        ll tmp = pre[i] + suf[i+1];
        if(tmp>mx){
            l = preind[i];
            r = sufind[i+1];
        }
        mx = max(mx, tmp);
    }
    
    cout<<l+1<<" "<<r+1<<endl;
    
    return 0;
}
