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
    
    ll n,m,h,x;
    cin>>n>>m>>h;
    
    ll arr[n][m];
    
    vector<ll> front(m);
    
    for(ll i=0;i<m;i++){
        cin>>front[i];
        for(ll j=0;j<n;j++)
            arr[j][i] = front[i];
    }
    
    for(ll i=0;i<n;i++){
        cin>>x;
        
        for(ll j=0;j<m;j++){
            if(x>front[j])
                continue;
            arr[i][j] = x;
        }
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>x;
            if(!x)
                arr[i][j] = 0;
        }
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}