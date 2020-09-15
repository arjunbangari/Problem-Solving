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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll i = 1, ans = arr[0];
        while(i<n){
            if(!arr[i]){
                i++;
                continue;
            }
            
            ll j = i;
            while(j<n && arr[j]==arr[i])
                j++;
            ans += (j-i)/3;
            i = j;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}