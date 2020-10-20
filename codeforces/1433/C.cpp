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
        
        set<ll> s;
        for(auto u: arr)
            s.insert(u);
        
        if(s.size()==1){
            cout<<-1<<endl;
            continue;
        }
        
        ll mx = *max_element(all(arr));
        
        ll ind = 0;
        for(ll i=0;i<n;i++){
            if(arr[i]==mx){
                if(i>0 && arr[i-1]<arr[i]){
                    ind = i+1;
                    break;
                }
                if(i<n-1 && arr[i+1]<arr[i]){
                    ind = i+1;
                    break;
                }
            }
        }
        
        cout<<ind<<endl;
    }
    
    return 0;
}