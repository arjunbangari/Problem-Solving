#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m,b=0,w=0;
        cin>>n>>m;
        
        char ans[n][m];
        
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if((i+j)%2){
                    ans[i][j] = 'W';
                    w++;
                } else {
                    ans[i][j] = 'B';
                    b++;
                }
            }
        }
        
        if(b==w){
            for(ll i=0;i<n;i++){
                ll flag=0;
                for(ll j=0;j<m;j++){
                    if(ans[i][j]=='W'){
                        ans[i][j] = 'B';
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++)
                cout<<ans[i][j];
            cout<<endl;
        }
        
    }
    
    return 0;
}