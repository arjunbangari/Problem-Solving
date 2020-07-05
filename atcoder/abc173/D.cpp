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

    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    sort(arr.rbegin(), arr.rend());
    
    ll ans = arr[0], cur = 1, i = 2, flag = 0;
    
    while(i<n){
        ans += arr[cur];
        i++;
        flag++;
        if(flag==2){
            cur++;
            flag = 0;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}
