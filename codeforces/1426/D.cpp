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

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n+2);
    for(ll i=2;i<=n+1;i++)
        cin>>arr[i];
    
    ll last = -1, ans=0;
    map<ll, ll> mp;
    mp[0] = 1;
    
    for(ll i=2;i<=n+1;i++){
        arr[i] += arr[i-1];
        if(mp[arr[i]] && mp[arr[i]]>=last){
            ans++;
            last = i-1;
        }
        mp[arr[i]] = i;
    }
    
    cout<<ans<<endl;
    
    return 0;
}