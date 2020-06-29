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
    
    vector<ll> height(n);
    for(auto &u: height)
        cin>>u;
    
    vector<ll> arr(maxn);
    for(auto u: height)
        arr[u+1]--;
    
    arr[1] = n;
    for(ll i=2;i<maxn;i++)
        arr[i] += arr[i-1];
    
    ll mx = *max_element(height.begin(), height.end());
    ll mn = *min_element(height.begin(), height.end());
    
    ll i = mx, slices = 0;
    
    while(i>mn){
        ll cost = arr[i], j = i-1;
        while(j>mn){
            if((cost+arr[j])>k)
                break;
            cost += arr[j];
            j--;
        }
        slices++;
        i = j;
    }
    
    cout<<slices<<endl;
    
    return 0;
}