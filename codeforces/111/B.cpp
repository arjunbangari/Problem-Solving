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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(maxn);
    
    for(ll i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        
        ll cnt = 0;
        
        for(ll j=1;j<=sqrt(x);j++){
            if(x%j==0){
                if(arr[j]<(i-y))
                    cnt++;
                arr[j] = i;
                
                ll p = x/j;
                if(arr[p]<(i-y))
                    cnt++;
                arr[p] = i;
            }
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}