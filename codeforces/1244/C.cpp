#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    
    ll wins, draws, loss, flag=0;
    
    for(ll i=0;i<w;i++){
        ll temp = p - i*d;
        if(temp>=0 && temp%w==0){
            ll x = temp/w;
            if( (x+i)<=n ){
                flag = 1;
                wins = x;
                draws = i;
                loss = n - wins - draws;
                break;
            }
        }
    }
    
    if(flag)
        cout<<wins<<" "<<draws<<" "<<loss<<endl;
    else
        cout<<-1<<endl;
    
    return 0;
}