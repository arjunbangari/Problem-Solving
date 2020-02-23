#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool isprime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

int main(){
    fast;
    int n;
    cin>>n;
    set<int> s;
    
    for(int i=2;i<=n;i++){
        if(isprime(i)){
            int j=i;
            while(j<=n){
                s.insert(j);
                j *= i;
            }
        }
    }
    
    cout<<s.size()<<endl;
    for(auto i : s)
        cout<<i<<" ";
    
    return 0;
}