#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ld> arr(n), brr(n);
    for(auto &u: arr)
        cin>>u;
    for(auto &u: brr)
        cin>>u;
    
    map<ld, ll> mp;
    ll ans = 0, cnt = 0;
    for(ll i=0;i<n;i++){
        if(arr[i]==0){
            if(brr[i]==0)
                cnt++;
            continue;
        }
        ld x = (-brr[i])/arr[i];
        mp[x]++;
        ans = max(ans, mp[x]);
    }
    
    cout<<ans+cnt<<endl;
    
    return 0;
}