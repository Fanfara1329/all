#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    Node *l = nullptr, *r = nullptr;

    Node(int x) {
        this->x = x;
    }

    Node(Node *l, Node *r) {
        this->l = l;
        this->r = r;
        x = l->x + r->x;
    }
};

Node *build(int l, int r, vector<int> &v) {
    if (r == l)
        return new Node(v[l]);
    Node *tl = build(l, (r + l) >> 1, v);
    Node *tr = build(((r + l) >> 1) + 1, r, v);
    return new Node(tl, tr);
}

int ireq(Node *n, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) {
        return n->x;
    }
    int mid = (r + l) >> 1;
    if (tr <= mid)
        return ireq(n->l, l, mid, tl, tr);
    else if (mid + 1 <= tl) {
        return ireq(n->r, mid + 1, r, tl, tr);
    } else
        return ireq(n->l, l, mid, tl, tr) + ireq(n->r, mid + 1, r, tl, tr);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &el : v)
        cin >> el;
    Node *st = build(0, n - 1, v);
    int m, a, b;
    cin >> m;
    //cout << st->x << ' ' << st->l->x << ' ' << st->r->x << "\n";
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        a--;
        b--;
        cout << ireq(st, 0, n - 1, a, b) << "\n";
    }
}