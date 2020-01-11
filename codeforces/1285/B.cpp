#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll maxs(ll a[], ll k, ll j) {
    ll max_so_far = -1e10, max_ending_here = 0;
    for (ll i = k; i < j; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,sum=0;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        ll temp1 = maxs(arr,0,n-1);
        ll temp2 = maxs(arr,1,n);
        ll temp = max(temp1,temp2);
        if(temp>=sum)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

    return 0;
}
