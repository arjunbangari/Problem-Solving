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
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    if(n==2){
        cout<<min(arr[0], arr[1]) - 1<<endl;
        return 0;
    }
    
    if(n==1){
        cout<<arr[0]-1<<endl;
        return 0;
    }
    
    sort(arr.begin(), arr.end());
    
    ll m = 1e5;
    ll x = pow(2.0, ((ld)log2(inf)/(ld)(n-1)));
    x = min(m, x);

    ll ans = inf;
    
    for(ll i=1;i<=x;i++){
        vector<ll> brr(n);
        brr[0] = 1;
        for(ll j=1;j<n;j++)
            brr[j] = brr[j-1] * i;
            
        ll sum = 0;
        for(ll j=0;j<n;j++)
            sum += abs(arr[j] - brr[j]);
        
        ans = min(sum, ans);
    }
    
    cout<<ans<<endl;
    
    return 0;
}