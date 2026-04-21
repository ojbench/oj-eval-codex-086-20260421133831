#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<int> L(n+1), R(n+1);
    for(int i=1;i<=n;++i){
        int a,b;
        cin >> a >> b;
        L[i]=a; R[i]=b;
    }

    // Compute depth for each node from root=1
    vector<int> depth(n+1, 0);
    queue<int> q;
    depth[1]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(u==-1) continue;
        if(L[u]!=-1){ depth[L[u]]=depth[u]+1; q.push(L[u]); }
        if(R[u]!=-1){ depth[R[u]]=depth[u]+1; q.push(R[u]); }
    }

    int t;
    cin >> t;

    function<void(int, vector<int>&)> inorder = [&](int u, vector<int>& out){
        if(u==-1) return;
        inorder(L[u], out);
        out.push_back(u);
        inorder(R[u], out);
    };

    for(int qi=0; qi<t; ++qi){
        int k; cin >> k;
        for(int i=1;i<=n;++i){
            if(depth[i] && depth[i] % k == 0){
                swap(L[i], R[i]);
            }
        }
        vector<int> out; out.reserve(n);
        inorder(1, out);
        for(size_t i=0;i<out.size();++i){
            cout << out[i];
            if(i+1<=out.size()) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
