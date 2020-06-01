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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n, k, c, x;
        cin>>n>>k;
        
        vector<set<ll>> arr(k);
        for(ll i=0;i<k;i++){
            cin>>c;
            for(ll j=0;j<c;j++){
                cin>>x;
                arr[i].insert(x);
            }
        }
        
        ll mx;
        
        cout<<"? "<<n<<" ";
        for(ll i=1;i<=n;i++)
            cout<<i<<" ";
        cout.flush();
        
        cin>>mx;
        
        if(mx==-1)
            return 0;
        
        ll l = 1, r = n;
        
        while(l<r){
            ll mid = (l+r)/2;
            
            cout<<"? "<<mid-l+1<<" ";
            for(ll i=l;i<=mid;i++)
                cout<<i<<" ";
            cout.flush();
            cin>>x;
            
            if(x==-1)
                return 0;
            
            if(x==mx)
                r = mid;
            else
                l = mid+1;
        }
        
        ll ind=-1;
        
        for(ll i=0;i<k;i++){
            if(arr[i].count(r)){
                ind = i;
                break;
            }
        }
            
        if(ind==-1){
            cout<<"! ";
            for(ll i=0;i<k;i++)
                cout<<mx<<" ";
            cout.flush();
        } else {
            
            ll mx2, sz = arr[ind].size();
            
            cout<<"? "<<n-sz<<" ";
            for(ll i=1;i<=n;i++){
                if(!arr[ind].count(i))
                    cout<<i<<" ";
            }
            cout.flush();
            cin>>mx2;
            
            if(mx2==-1)
                return 0;
                
            cout<<"! ";
            for(ll i=0;i<k;i++){
                if(i!=ind)
                    cout<<mx<<" ";
                else
                    cout<<mx2<<" ";
            }
            cout.flush();
        }
        
        string ans;
        cin>>ans;
        cout.flush();
        
        if(ans=="Incorrect")
            return 0;
    }
    
    return 0;
}