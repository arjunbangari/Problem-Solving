#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll q;
    cin>>q;
    
    vector<ll> last_query(n+1, 0);
    vector<ll> qind;
    vector<ll> qval;
    
    for(ll z=1;z<=q;z++){
        ll type, p, x;
        cin>>type;
        
        if(type==1){
            cin>>p>>x;
            arr[p] = x;
            last_query[p] = z;
        }
        else{
            cin>>x;
            qind.push_back(z);
            qval.push_back(x);
        }
    }
    
    ll sz = qval.size();
    
    for(ll i=sz-2;i>=0;i--)
        qval[i] = max(qval[i], qval[i+1]);
    
    for(ll i=1;i<=n;i++){
        auto temp = lower_bound(qind.begin(), qind.end(), last_query[i] );
        
        if(temp!=qind.end()){
            auto val = temp - qind.begin();
            cout<< max( arr[i], qval[val] ) << " ";
        } else {
            cout<<arr[i]<<" ";
        }
    }
    
    return 0;
}