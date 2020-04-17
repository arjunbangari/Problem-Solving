#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n,p;
    cin>>n>>p;
    
    string s;
    cin>>s;
    
    ll ans = 0;
    p--;
    
    ll l,r;
    if(p<n/2){
        l = 0;
        r = n/2;
    } else {
        l = n/2;
        r = n;
    }
    
    ll left = p, right = p;
    
    for(ll i=p;i>=l;i--){
        if(s[i]!=s[n-i-1]){
            ll temp = abs(s[i]-s[n-i-1]);
            ans += min(temp, 26 - temp);
            left = i;
        }
    }
    
    for(ll i=p+1;i<r;i++){
        if(s[i]!=s[n-i-1]){
            ll temp = abs(s[i]-s[n-i-1]);
            ans += min(temp, 26 - temp);
            right = i;
        }
    }
    
    
    ans += (p-left) + (right-p) + min(p-left, right-p);
    
    cout<<ans<<endl;
    
    return 0;
}