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
    
    ll n,m;
    cin>>n>>m;
    
    ll arr[n][m], brr[n][m];
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            brr[i][j] = 0;
        }
    }
    
    ll k = 0;
    vector<pll> op;
    
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<m-1;j++){
            if(arr[i][j]==1 && arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1){
                k++;
                op.push_back({i+1, j+1});
                brr[i][j] = 1;
                brr[i][j+1] = 1;
                brr[i+1][j] = 1;
                brr[i+1][j+1] = 1;
            }
        }
    }
    
    ll flag = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]!=brr[i][j])    
                flag = 1;
        }
    }
    
    if(flag){
        cout<<-1<<endl;
    } else {
        cout<<k<<endl;
        for(auto u: op)
            cout<<u.first<<" "<<u.second<<endl;
    }
    return 0;
}