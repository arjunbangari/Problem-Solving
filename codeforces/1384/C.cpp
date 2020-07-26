#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        string a,b;
        cin>>a>>b;
        
        ll arr[26][26] = {0};
        
        ll flag = 0;
        
        for(ll i=0;i<n;i++){
            if(b[i]<a[i])
                flag = 1;
            if(b[i]>a[i])
                arr[a[i]-'a'][b[i]-'a']++;
        }
        
        if(flag){
            cout<<-1<<endl;
            continue;
        }
        
        ll ans = 0;
        
        for(ll i=0;i<26;i++){
            ll j;
            for(j=0;j<26;j++){
                if(arr[i][j])
                    break;
            }
            
            if(j==26)
                continue;
            
            for(ll k=j+1;k<26;k++)
                arr[j][k] += arr[i][k];
            ans++;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}