#include <iostream> 
#include <vector> 
using namespace std; 
int main() 
{ 
    int N; 
    cin >> N; 
    vector<int> v(N), L(N, 0), R(N, 0); 
    int maxi = 0; 
    for (int i = 0; i < N; i++) 
    { 
        cin >> v[i]; 
        if (v[i] > maxi) 
        { 
            L[i] = 1; 
            maxi = v[i]; 
        }            
    } 
    int mini = v[N - 1] + 1; 
    for (int i = N - 1; i >= 0; i--) 
    { 
        if (v[i] < mini) 
        { 
            R[i] = 1; 
            mini = v[i]; 
        } 
    } 
    vector<int> ans; 
    for (int i = 0; i < N; i++) 
        if (L[i] && R[i]) 
            ans.push_back(v[i]); 
    cout << ans.size() << endl; 
    for (int i = 0; i < ans.size(); i++) 
    { 
        if (i != 0) 
            cout << " "; 
        cout << ans[i]; 
    } 
    cout<<endl; 
    return 0; 
}