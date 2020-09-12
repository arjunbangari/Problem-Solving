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
        
        vector<ll> arr(n), cnt(105);
        for(auto &u: arr){
            cin>>u;
            cnt[u]++;
        }
        
        ll mx = 0, dmx = 0;
        
        for(ll i=0;i<101;i++){
            if(!cnt[i]){
                mx = i;
                break;
            }
        }
        
        for(ll i=0;i<101;i++){
            if(cnt[i]<2){
                dmx = i;
                break;
            }
        }
        
        cout<<mx + dmx<<endl;
    }
    
    return 0;
}