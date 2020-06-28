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
    
    ll n,m;
    cin>>n>>m;
    
    vector<pll> arr(m);
    for(ll i=0;i<m;i++)
        cin>>arr[i].first>>arr[i].second;
    
    ll ans = max(arr[0].first-1+arr[0].second, n-arr[m-1].first + arr[m-1].second);
    
    for(ll i=1;i<m;i++){
        ll dx = arr[i].first - arr[i-1].first;
        ll mx = arr[i-1].second+dx;
        ll mn = arr[i-1].second-dx;
        
        if(arr[i].second>mx || arr[i].second<mn){
            // cout<<i<<" "<<mx<<" "<<mn<<" "<<arr[i].first<<endl;
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        
        ans = max(ans, (dx + arr[i].second + arr[i-1].second)/2);
        ans = max(ans, arr[i].second);
    }
    
    cout<<ans<<endl;
    
    return 0;
}