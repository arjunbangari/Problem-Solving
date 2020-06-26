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
    
    ll k;
    cin>>k;
    
    ll n=-1 , m=-1;
    for(ll i=5;i<=sqrt(k);i++){
        if(k%i==0){
            if((k/i)>=5){
                n = i;
                m = k/i;
                break;
            }
        }
    }
    
    if(n==-1){
        cout<<-1<<endl;
        return 0;
    }
    
    string alpha("aeiou");
    
    ll arr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<alpha[(i+j)%5];
        }
    }
    
    return 0;
}