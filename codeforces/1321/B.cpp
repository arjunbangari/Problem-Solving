#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define loop for(int i=0;i<n;++i)
#define loopitr(s) for(auto it=(s).begin();it!=(s).end();++it)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll brr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>brr[i];
    
    map<ll,ll> mp;
    ll ans=-1;
    
    for(ll i=1;i<=n;i++){
        ll temp = i - brr[i];
        mp[temp] += brr[i];
        ans = max(ans, mp[temp]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}