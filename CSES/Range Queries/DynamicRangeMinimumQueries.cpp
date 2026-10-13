#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> t;
void build(const vector<int>& a, int l, int r, int node) {
    if (l == r) {
        t[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(a, l, m, node * 2);
    build(a, m + 1, r, node * 2 + 1);
    t[node] = min(t[2 * node], t[2 * node + 1]);
}
int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INT_MAX;
    if (ql <= l && r <= qr) return t[node];
    int m = (l + r) / 2;
    return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
}
void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
        t[node] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
        update(2 * node, l, m, pos, val);
    else
        update(2 * node + 1, m + 1, r, pos, val);
    t[node] = min(t[2 * node], t[2 * node + 1]);
}
int main() {
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    t.assign(4 * n, 0);
    build(a, 0, n - 1, 1);
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            update(1, 0, n - 1, l - 1, r);
        } else
            cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
    }
}
