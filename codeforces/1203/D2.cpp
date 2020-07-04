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
    
    string s, t;
    cin>>s>>t;
    
    ll n = s.length(), m = t.length();
    vector<ll> pre(m), suf(m);
    
    ll cur = 0;
    
    for(ll i=0;i<n;i++){
        if(s[i]==t[cur]){
            pre[cur] = i;
            cur++;
        }
        if(cur==m)
            break;
    }
    
    cur = m-1;
    for(ll i=n-1;i>=0;i--){
        if(s[i]==t[cur]){
            suf[m - cur - 1] = n-i-1;
            cur--;
        }
        if(cur<0)
            break;
    }
    
    ll ans = max(n - pre[m-1]-1 , n - suf[m-1] -1);
    
    for(ll i=0;i<m-1;i++)
        ans = max(ans, n - (pre[i] + suf[m-i-2]+2));
    
    cout<<ans<<endl;
    
    return 0;
}