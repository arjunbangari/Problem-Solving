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
    
    ll n;
    cin>>n;
    
    char arr[55][55];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            cin>>arr[i][j];
    
    for(ll i=0;i<=n+1;i++){
        arr[i][0] = '#';
        arr[0][i] = '#';
        arr[n+1][i] = '#';
        arr[i][n+1] = '#';
    }
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(arr[i][j]=='.'){
                if(arr[i-1][j]=='.' && arr[i+1][j]=='.' && arr[i][j-1]=='.' && arr[i][j+1]=='.'){
                    arr[i][j] = '#';
                    arr[i-1][j] = '#';
                    arr[i+1][j] = '#';
                    arr[i][j-1] = '#';
                    arr[i][j+1] = '#';
                }
                    
            }
        }
    }
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(arr[i][j]=='.'){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"YES"<<endl;
    
    return 0;
}
