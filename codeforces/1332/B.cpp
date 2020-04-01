#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll num = 500;
vector<char> is_prime(505, true);
vector<ll> primes;

void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= num; i++) {
        if (is_prime[i] && (long long)i * i <= num) {
            for (int j = i * i; j <= num; j += i)
                is_prime[j] = false;
        }
    }
    for(ll i=2;i<505;i++)
        if(is_prime[i])
            primes.push_back(i);
}


int main(){
    fast;
    
    sieve();
    ll sz = primes.size();
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll vis[n] = {0};
        ll colors[n] = {0};
        ll cnt=1;
        
        for(ll i=0;i<sz;i++){
            ll flag = 0;
            for(ll j=0;j<n;j++){
                if(!vis[j] && arr[j]%primes[i]==0){
                    colors[j] = cnt;
                    vis[j] = 1;
                    flag = 1;
                }
            }
            if(flag)
                cnt++;
        }
        
        cout<<cnt-1<<endl;
        for(ll i=0;i<n;i++)
            cout<<colors[i]<<" ";
        cout<<endl;
        
    }
    
    return 0;
}