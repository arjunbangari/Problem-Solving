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

map<ll, ll> mp; 

void find_divisors(ll n){
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i==(n/i))
                mp[i]++;
            else{
                mp[i]++;
                mp[n/i]++;
            }
        }
    }
}

int main(){
    fast;
    
    ll a,b;
    cin>>a>>b;
    
    find_divisors(a);
    find_divisors(b);
    
    vector<ll> common;
    
    for(auto u: mp){
        if(u.second==2)
            common.push_back(u.first);
    }
    
    sort(common.begin(), common.end());
    
    ll n;
    cin>>n;
    
    while(n--){
        ll low, high;
        cin>>low>>high;
        
        ll ans = -1;
        
        auto temp = lower_bound(common.begin(), common.end(), high);
        
        if(temp==common.end())
            temp--;
        
        if(*temp<=high && *temp>=low){
            ans = *temp;
        } else {
            if(temp!=common.begin()){
                temp--;
                if(*temp<=high && *temp>=low)
                    ans = *temp;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}