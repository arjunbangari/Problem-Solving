#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n,b,a;
    cin>>n>>b>>a;
    ll x=b, y=a;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll i=0;
    
    while(i<n){
        if(x==0 && y==0)
            break;
        if(arr[i]==1){
            if(y==a)
                y--;
            else{
                if(x>0){
                    x--;
                    y++;
                } else {
                    y--;
                }
            }
        } else {
            if(y==0)
                x--;
            else
                y--;
        }
        i++;
    }
    
    cout<<i<<endl;
    
    return 0;
}