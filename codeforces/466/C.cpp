#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast; 
    ll n;
    cin>>n;
    ll arr[n];
    ll s = 0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        s += arr[i];
    }
    
    if(s%3!=0 || n<3)
        cout<<0<<"\n";
    else{
        ll temp = s/3,ans=0;
        vector<ll> single;
        vector<ll> doubl;
        if(arr[0]==temp)
            single.push_back(0);
            
        for(ll i=1;i<n;i++){
            arr[i] += arr[i-1];
            if(arr[i]==temp)
                single.push_back(i);
            else if(arr[i]==2*temp)
                doubl.push_back(i);
        }
        
        if(temp==0){
            ll m = single.size();
            ans = ((m-1)*(m-2))/2;
        } else {
            sort(single.begin(),single.end());
            sort(doubl.begin(),doubl.end());
            ll ss = single.size();
            ll ds = doubl.size();
            for(ll i=0;i<ss;i++){
                vector<ll>::iterator upper;
                upper = upper_bound(doubl.begin(),doubl.end(),single[i]);
                if(upper!=doubl.end()){
                    ans += doubl.end() - upper;
                }
            }
        }
        cout<<ans<<"\n";
        
    }
    return 0;
}
