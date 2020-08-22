#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
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
        
        ll mn = *min_element(all(arr));
        
        vector<ll> pos, tmp;
        for(ll i=0;i<n;i++){
            if(arr[i]%mn==0){
                pos.push_back(i);
                tmp.push_back(arr[i]);
            }
        }
        
        sort(all(tmp));
        ll sz = pos.size();
        
        for(ll i=0;i<sz;i++)
            arr[pos[i]] = tmp[i];
        
        string ans = "YES";
        for(ll i=1;i<n;i++){
            if(arr[i]<arr[i-1])
                ans = "NO";
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}