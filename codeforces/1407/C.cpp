#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n+1);
    
    ll mx = 1, val1, val2;
    for(ll i=2;i<=n;i++){
        cout<<"? "<<mx<<" "<<i<<endl;
        cin>>val1;
        cout<<"? "<<i<<" "<<mx<<endl;
        cin>>val2;
        
        if(val1>val2){
            arr[mx] = val1;
            mx = i;
        } else {
            arr[i] = val2;
        }
    }
    
    arr[mx] = n;
    
    cout<<"! ";
    for(ll i=1;i<=n;i++)    
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}