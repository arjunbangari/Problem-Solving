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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<ll> cnt(maxn,0), cnt1(maxn, 0);
    
    set<ll> s;
    
    for(ll i=0;i<n;i++){
        cnt1[arr[i]]++;
        if(s.count(arr[i]))
            continue;
        for(ll j=arr[i];j<maxn;j+=arr[i]){
            cnt[j]++;
        }
        s.insert(arr[i]);
    }
    
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(cnt[arr[i]]==1 && cnt1[arr[i]]==1)
            ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}
