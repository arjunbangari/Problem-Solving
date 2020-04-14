#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,v;
    cin>>n>>m>>v;
    
    if(m<(n-1) || m>(((n-1)*(n-2))/2 + 1))
        cout<<-1<<endl;
    else{
        ll temp = ( v==1 ? 2 : 1 );
        
        cout<<temp<<" "<<v<<endl;
        m--;
        
        for(ll i=1;i<=n;i++){
            if(i==temp)
                continue;
            if(m<=0)
                break;
            for(ll j=i+1;j<=n;j++){
                if(j==temp)
                    continue;
                if(m>0)
                    cout<<i<<" "<<j<<endl;
                else
                    break;
                m--;
            }
        }
    }
    
    return 0;
}