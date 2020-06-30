#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    vector<pll> arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i].second>>arr[i].first;
    
    sort(arr.begin(), arr.end());
    
    multiset<ll> ms;
    vector<ll> brr(n);
    ll i = n-1, cnt = 0, sum = 0;
    
    while(i>=0){
        brr[i] = sum;
        if(cnt<(k-1)){
            ms.insert(arr[i].second);
            sum += arr[i].second;
            cnt++;
        } else if(!ms.empty()) {
            ll val = *ms.begin();
            if(val<arr[i].second){
                sum += arr[i].second -  val;
                ms.erase(ms.begin());
                ms.insert(arr[i].second);
            }
        }
        i--;
    }
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++)
        ans = max(ans , arr[i].first*(arr[i].second + brr[i]));
    
    cout<<ans<<endl;
    return 0;
}