#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> arr;
ll root(ll i){
    ll count=1;
    while(i!=arr[i]){
        count++;
        i = arr[i];
    }
    return count;
}

int main(){
    fast;
    ll n,last=1;
    cin>>n;
    map<string, ll> mp;
    arr.push_back(0);
    mp["Polycarp"] = 0;
    
    for(ll i=0;i<n;i++){
        string name1,temp,name2;
        cin>>name1>>temp>>name2;
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower); 
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower); 
        if(mp.find(name1)==mp.end())
            mp[name1] = last++;
        arr.push_back(mp[name2]);
    }
    ll mx=0;
    for(ll i=0;i<arr.size();i++){
        //cout<<i<<" "<<arr[i]<<endl;
        mx = max(mx,root(i));
    }
    cout<<mx<<"\n";
    return 0;
}