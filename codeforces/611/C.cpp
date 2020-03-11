#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    string arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        
    //precalculation    
    
    ll dpr[n][m], dpc[m][n];
    
    // horizontally
    for(ll i=0;i<n;i++)
        dpr[i][0] = 0;
    
    for(ll i=0;i<n;i++){
        for(ll j=1;j<m;j++){
            if(arr[i][j]=='.' && arr[i][j-1]=='.')
                dpr[i][j] = dpr[i][j-1] + 1;
            else
                dpr[i][j] = dpr[i][j-1];
        }
    }
    
    // vertically
    for(ll i=0;i<m;i++)
        dpc[i][0] = 0;
    
    for(ll i=0;i<m;i++){
        for(ll j=1;j<n;j++){
            if(arr[j][i]=='.' && arr[j-1][i]=='.')
                dpc[i][j] = dpc[i][j-1] + 1;
            else
                dpc[i][j] = dpc[i][j-1];
        }
    }
    
    // queries
    ll q;
    cin>>q;
    
    while(q--){
        ll r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;
        r2--;
        c1--;
        c2--;
        ll ans = 0;
        for(ll i=r1;i<=r2;i++)
            ans += ( dpr[i][c2] - dpr[i][c1] );
        for(ll i=c1;i<=c2;i++)
            ans += ( dpc[i][r2] - dpc[i][r1] );
        cout<<ans<<endl;
    }
    
    return 0;
}