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

vector<ll> divisors;

void find_divisors(ll k){
    for(ll i=1;i<=sqrt(k);i++){
        if(k%i==0){
            if(k/i==i)
                divisors.push_back(i);
            else{
                divisors.push_back(i);
                divisors.push_back(k/i);
            }
        }
    }
    
    sort(divisors.begin(), divisors.end());
}

int main(){
    fast;
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    find_divisors(k);
    
    vector<ll> arr(n), brr(m);
    for(auto &u: arr)
        cin>>u;
    for(auto &u: brr)
        cin>>u;
        
    vector<ll> a,b;
    
    ll i=0;
    while(i<n){
        if(arr[i]){
            ll j = i+1;
            while(j<n && arr[j])
                j++;
            a.push_back(j-i);
            i = j;
        } else {
            i++;
        }
    }
    
    i = 0;
    while(i<m){
        if(brr[i]){
            ll j = i+1;
            while(j<m && brr[j])
                j++;
            b.push_back(j-i);
            i = j;
        } else {
            i++;
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll sza = a.size();
    ll szb = b.size();
    
    if(!sza || !szb){
        cout<<0<<endl;
        return 0;
    }
    
    vector<ll> psum(sza), qsum(szb);
    psum[0] = a[0];
    qsum[0] = b[0];
    
    for(ll i=1;i<sza;i++)
        psum[i] = psum[i-1] + a[i];
    for(ll i=1;i<szb;i++)
        qsum[i] = qsum[i-1] + b[i];
    
    ll ans = 0;
    
    for(auto u: divisors){
        
        ll x = k/u;
        
        auto temp1 = lower_bound(a.begin(), a.end(), u);
        auto temp2 = lower_bound(b.begin(), b.end(), x);
        
        // if(u==1)
        //     cout<<*temp2<<endl;
        
        if(temp1==a.end() || temp2==b.end())
            continue;
        
        ll sum1, sum2, len1, len2;
        
        if(temp1==a.begin()){
            sum1 = psum[sza-1];
            len1 = sza;
        } else {
            len1 = a.end() - temp1;
            sum1 = psum[sza-1] - psum[sza - len1 - 1];
        }
        
        if(temp2==b.begin()){
            sum2 = qsum[szb-1];
            len2 = szb;
        } else {
            len2 = b.end() - temp2;
            sum2 = qsum[szb-1] - qsum[szb - len2 - 1];
        }
    
        ans += (sum1 - len1*(u-1))*(sum2 - len2*(x-1));
    }
    
    cout<<ans<<endl;
    
    return 0;
}