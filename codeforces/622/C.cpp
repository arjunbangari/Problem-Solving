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
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    vector<ll> brr(n+1);
    brr[1] = -1;
    
    for(ll i=2;i<=n;i++)
        brr[i] = ( arr[i]!=arr[i-1] ? i-1 : brr[i-1] );
    
    while(m--){
        ll l,r,x;
        cin>>l>>r>>x;
        
        if(arr[r]!=x){
            cout<<r<<endl;
        } else {
            if(brr[r]>=l){
                cout<<brr[r]<<endl;
            } else {
                cout<<-1<<endl;
            }
        }
    }
    
    return 0;
}