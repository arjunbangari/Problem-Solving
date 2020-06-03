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
    
    vector< vector<ll>> arr(n, vector<ll> (m));
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    
    if(n==1){
        
        for(ll i=0;i<m;i++){
            if(arr[0][i]!=0){
                cout<<"TAK"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
        }
        
        cout<<"NIE"<<endl;
        return 0;
    }
    
    set<ll> s;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            s.insert(arr[i][j]);
        
    ll sz = s.size();
    
    if(sz==1){
        cout<<"NIE"<<endl;
        return 0;
    }
    
    ll xr = 0;
    
    for(ll i=0;i<n;i++)
        xr ^= arr[i][0];
    
    if(xr>0){
        cout<<"TAK"<<endl;
        for(ll i=0;i<n;i++)
            cout<<1<<" ";
        return 0;
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            xr ^= arr[i][0];
            xr ^= arr[i][j];
            
            if(xr>0){    
                cout<<"TAK"<<endl;
                
                for(ll k=0;k<i;k++)
                    cout<<1<<" ";
                cout<<j+1<<" ";
                for(ll k=i+1;k<n;k++)
                    cout<<1<<" ";
                return 0;
            }
            
            xr ^= arr[i][j];
            xr ^= arr[i][0];
        }
    }
    
    cout<<"NIE"<<endl;
    
    return 0;
}