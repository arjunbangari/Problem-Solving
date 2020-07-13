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
    
    ll n,m, sum = 0;
    cin>>n>>m;
    
    vector<ll> arr(n);
    for(auto &u: arr){
        cin>>u;
        sum += u;
    }
    
    sort(arr.rbegin(), arr.rend());
    arr.push_back(0);
    ll ans = 0, cnt = 0;
    
    for(ll i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            cnt++;
            ans++;
            continue;
        }
        ll dif = arr[i]-arr[i+1];
        if(cnt>=dif){
            ans++;
            cnt = cnt - dif + 1;
        } else {
            ans += dif - cnt;
            cnt = 0;
        }
    }
    
    cout<<sum - ans<<endl;
    
    return 0;
}