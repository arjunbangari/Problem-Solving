#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

ll n;
vector<string> arr;
ll id[200009];
ll sz[200009];

void initialise(){
    for(ll i=0;i<=n;i++){
        id[i] = i;
        sz[i] = 1;
   }
}

ll root(ll i){
    while(i!=id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool connected(ll p , ll q){
    return(root(p)==root(q));
}

void uni(ll p, ll q){
    ll proot = root(p);
    ll qroot = root(q);
    if(sz[proot]>sz[qroot]){
        id[qroot] = id[proot];
        sz[proot] += sz[qroot];
    }
    else{
        id[proot] = id[qroot];
        sz[qroot]+=sz[proot];
    }
}

int main(){
    fast; 
    cin>>n;
    initialise();
    string s;
    map<char,ll> mp; 
    string temp="a";
    arr.push_back(temp);
    for(ll i=0;i<n;i++){
        cin>>s;
        sort(s.begin(),s.end());
        arr.push_back(s);
    }
    
    sort(arr.begin(),arr.end());
    
    for(ll i=1;i<=n;i++){
        if(mp.find(arr[i][0])!=mp.end()){
            uni(mp[arr[i][0]],i);
        } else {
            mp[arr[i][0]] = i;
        }
        for(ll j=0;j<arr[i].size();j++){
            if(mp.find(arr[i][j])==mp.end())
                mp[arr[i][j]] = i;
        }
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        if(id[i]==i)
            ans++;
    }
    cout<<ans<<"\n";
    
    return 0;
}
