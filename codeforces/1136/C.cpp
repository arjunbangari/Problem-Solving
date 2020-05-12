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
    
    ll arr[n][m], brr[n][m];
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
            
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>brr[i][j];
            
    string ans = "YES";
        
    for(ll i=0;i<n+m;i++){
        vector<ll> a,b;
        
        for(ll j=0;j<n;j++){
            for(ll k=0;k<m;k++){
                if((j+k)==i){
                    a.push_back(arr[j][k]);
                    b.push_back(brr[j][k]);
                }
            }
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        if(a!=b){
            ans = "NO";
            break;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}