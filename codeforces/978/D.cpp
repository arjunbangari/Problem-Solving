#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    if(n<=2)
        cout<<0<<endl;
    else{
        ll ans = 1e7;
        
        for(ll i=-1;i<=1;i++){
            for(ll j=-1;j<=1;j++){
                ll first = arr[0] + i;
                ll second = arr[1] + j;
                ll d = second-first;
                ll count = abs(i) + abs(j);
                
                for(ll k=2;k<n;k++){
                    ll correct_value = first + k*d;
                    ll diff = abs(correct_value - arr[k]);
                    if(diff>1){
                        count = 1e7;
                        break;
                    } else {
                        count += diff;
                    }
                }
                ans = min(ans, count);
            }
        }
        cout<< ( ans==1e7 ? -1 : ans )<<endl;
    }

    return 0;
}