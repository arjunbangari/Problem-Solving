#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll sum = 0;
    for(auto u: arr)
        sum += u;
    
    if(sum<m){
        cout<<-1<<endl;
        return 0;
    }
    
    sort(arr.rbegin(), arr.rend());
    
    ll l = 1, r = n, ans;
    
    while(l<=r){
        ll x = (l+r)/2;
        ll cur = 0, i = 0, tmp = 0;
        
        while(i<n){
            ll k = i+x;
            for(;i<n && i<k;i++)
                tmp += max(0LL, arr[i]-cur);
            cur++;
        }
        
        if(tmp>=m){
            ans = x;
            r = x-1;
        } else
            l = x+1;
    }
    
    cout<<ans<<endl;
    
    return 0;
}