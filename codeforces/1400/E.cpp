#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> arr(maxn);

ll solve(ll l , ll r){
    if(l>r)
        return 0;
    
    if(l==r)
        return ( arr[l]==0 ? 0 : 1 );
    
    ll mn = *min_element(arr.begin()+l, arr.begin()+r+1);
    
    for(ll i=l;i<=r;i++)
        arr[i] -= mn;
    
    ll ans = mn;
    
    ll last = l;
    for(ll i=l;i<=r;i++){
        if(arr[i]==0){
            ans += solve(last, i-1);
            last = i+1;
        }
    }
    
    ans += solve(last, r);
    
    return min(ans, r-l+1);
    
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll ans = solve(0, n-1);
    
    cout<<ans<<endl;
    
    return 0;
}