#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e4+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    string a,b;
    cin>>a>>b;
    
    ll n = b.length(), m = a.length();
    vector<ll> cnt(m);
    
    for(ll i=0;i<m;i++){
        cnt[i] = ( a[i]=='1' ? 1 : 0 );
        if(i)
            cnt[i] += cnt[i-1];
    }
    
    ll one = 0;
    for(ll i=0;i<n;i++)
        if(b[i]=='1')
            one++;
    
    ll ans = 0;
    if(cnt[n-1]%2==one%2)
        ans++;
    
    for(ll i=n;i<m;i++){
        ll dif = cnt[i] - cnt[i-n];
        if(dif%2==one%2)
            ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}