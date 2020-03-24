#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    string matrix[n];
    for(ll i=0;i<n;i++)
        cin>>matrix[i];
    
    vector<ll> v[n];
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(matrix[i][j]=='1'){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    ll vis[n] = {0};
    
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            
            vector<ll> indices;
            vector<ll> values;
            queue<ll> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()){
                ll val = q.front();
                q.pop();
                indices.push_back(val);
                values.push_back(arr[val]);
                for(ll u: v[val]){
                    if(!vis[u]){
                        q.push(u);
                        vis[u] = 1;
                    }
                }
            }
            
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            
            ll sz=indices.size();
            
            for(ll j=0;j<sz;j++)
                arr[indices[j]] = values[j];

        }
    }
    
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}