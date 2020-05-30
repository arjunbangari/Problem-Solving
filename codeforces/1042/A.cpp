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
    
    ll n, m;
    cin>>n>>m;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll mn, mx, sum = 0;
    
    sort(arr.begin(), arr.end());
    
    mx = arr[n-1] + m;
    
    for(ll i=0;i<n;i++)
        sum += arr[i];
    
    ll temp = (sum + m + n -1)/n;
    
    mn = max(temp, arr[n-1]);
    
    cout<<mn<<" "<<mx<<endl;
    
    return 0;
}