#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

ll n,m;
ll id[105];
ll sz[105];

void initialise(){
    for(ll i=0;i<=m;i++){
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
    set <ll> mp;
    cin>>n>>m;
    initialise();
    ll ans=0,k,first,temp;
    
    for(ll i=0;i<n;i++){
        cin>>k;
        if(k==0)
            ans++;
        else{
            cin>>first;
            mp.insert(first);
            for(ll j=1;j<k;j++){
                cin>>temp;
                mp.insert(temp);
                uni(first,temp);
            }
        }
    }
    if(ans==n)
        cout<<n<<"\n";
    else{
        for(ll i=1;i<=m;i++)
            if(id[i]==i && mp.find(i)!=mp.end())
                ans++;
        cout<<ans-1<<"\n";
    }
    
    return 0;
}