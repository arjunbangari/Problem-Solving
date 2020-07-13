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
ll n,m,x,k,y;
vector<ll> arr(maxn), brr(maxn);

bool isSubSequence() { 
   int j = 0;  
   for (int i=0; i<=n&&j<=m; i++) {
        if(arr[i]==brr[j])
            j++;
   }
       
   return (j==(m+1)); 
} 

int main(){
    fast;

    cin>>n>>m;
    cin>>x>>k>>y;
    
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    for(ll j=1;j<=m;j++)
        cin>>brr[j];
    
    arr[0] = 0;
    arr[n+1] = n+1;
    brr[0] = 0;
    brr[m+1] = n+1;
    
    if(!isSubSequence()){
        cout<<-1<<endl;
        return 0;
    }
    
    ll cost = min(x, k*y), ans = 0;
    
    ll i = 0, j = 0;
    while(i<(m+1)){
        while(arr[j]!=brr[i])
            j++;
        
        ll ind1 = j;
        
        i++;
        
        while(arr[j]!=brr[i])
            j++;
        
        ll ind2 = j;
        ll l = ind2 - ind1 - 1, mx = -1, val = max(arr[ind1], arr[ind2]);
        if(i==(m+1))
            val = arr[ind1];
        
        for(ll p = ind1+1;p<ind2;p++)
            mx = max(mx, arr[p]);
        
        if(l<k && mx>val){
            cout<<-1<<endl;
            return 0;
        }
        
        if(mx>val){
            ans += x;
            l -= k;
        }
        ans += cost*(l/k);
        ans += (l%k)*y;
    }
    
    cout<<ans<<endl;
    
    return 0;
}