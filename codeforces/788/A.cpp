#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll maxs(vector<ll> a) { 
   ll size = a.size();
   ll max_so_far = 0, max_ending_here = 0; 
   for (ll i = 0; i < size; i++){ 
       max_ending_here = max_ending_here + a[i]; 
       if (max_ending_here < 0) 
           max_ending_here = 0; 
       else if (max_so_far < max_ending_here) 
           max_so_far = max_ending_here; 
   } 
   return max_so_far; 
}

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll temp[n-1];
    for(ll i=0;i<n-1;i++)
        temp[i] = abs(arr[i]-arr[i+1]);
    
    vector<ll> first,second;
    
    for(ll i=0;i<n-1;i++){
        if(i%2)
            first.push_back(-temp[i]);
        else
            first.push_back(temp[i]);
    }
        
    for(ll i=1;i<n-1;i++){
        if(i%2)
            second.push_back(temp[i]);
        else
            second.push_back(-temp[i]);
    }
        
        
    // cout<<"TEMP ARRAY : "<<endl;
    // for(ll i=0;i<n-1;i++)
    //     cout<<temp[i]<<" ";
    
    // cout<<endl<<"FIRST ARRAY : "<<endl;
    // for(ll i: first)
    //     cout<<i<<" ";
    
    // cout<<endl<<"SECOND ARRAY : "<<endl;
    // for(ll i: second)
    //     cout<<i<<" ";
    // cout<<endl;
    
    ll ans = max(maxs(first), maxs(second));
    cout<<ans<<endl;
    
    return 0;
}