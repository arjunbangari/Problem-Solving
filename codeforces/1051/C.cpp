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
    
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    vector<ll> cnt(105, 0);
    
    for(ll i=0;i<n;i++) 
        cnt[arr[i]]++;
    
    map<ll,ll> mp;
    for(ll i=1;i<=100;i++)
        mp[cnt[i]]++;
    
    ll a = mp[1]/2;
    
    vector<char> ans(n, 'A');
    
    for(ll i=0, k=0; i<n && k<a; i++){
        if(cnt[arr[i]]==1){
            ans[i] = 'B';
            k++;
        }
    }
    
    if(mp[1]%2){
        ll flag = 0;
        for(ll i=0;i<n;i++){
            if(cnt[arr[i]]>2){
                ans[i] = 'B';
                flag = 1;
                break;
            }
        }
        
        if(!flag){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
    for(ll i=0;i<n;i++)
        cout<<ans[i];
    
    return 0;
}