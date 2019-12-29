#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
          

int main(){
    int n=100009;
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> temp;
    for(int i=2;i<=n;i++){
        if(is_prime[i])
            temp.push_back(i);
    }
    //for(int i=0;i<30;i++)
    //    cout<<temp[i]<<" ";
    int x;
    cin>>x;
    auto upper1 = upper_bound(temp.begin(), temp.end(), x-1) - temp.begin();
    cout<<temp[upper1];
    return 0;
}
