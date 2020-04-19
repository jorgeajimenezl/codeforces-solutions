#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    int64_t sum, lazy;
    int size, prio;
    node *l, *r;
    bool rev;
    node (int value) : value(value), prio(rand()), 
                        sum(0), lazy(0),
                        rev(false), l(nullptr), r(nullptr) { }
};

int size (node* u) {
    return u ? u->size : 0;
}

int64_t sum (node* u) {
    return u ? u->sum : 0;
}

void push (node* u) {
    if (u && u->rev) {
        u->rev = 0;
        swap (u->l, u->r);

        if (u->l)  u->l->rev = !u->l->rev;
        if (u->r)  u->r->rev = !u->r->rev;
    }

    if (u && u->lazy) {
        u->value += u->lazy;
        
        if (u->l) u->l->lazy += u->lazy;
        if (u->r) u->r->lazy += u->lazy;

        u->lazy = 0;
    }
}

node* update (node* u) {
    if (u) {
        u->size = 1 + size(u->l) + size(u->r);
        u->sum = u->value + sum(u->l) + sum(u->r);
    }

    return u;
}

pair<node*, node*> split(node* u, int k) {
    push(u);
    
    if (!u)
        return {nullptr, nullptr};    

    if (size(u->l) >= k) {
        auto p = split(u->l, k);
        u->l = p.second;
        return make_pair(p.first, update(u));
    }
    else {
        auto p = split(u->r, k - size(u->l) - 1);
        u->r = p.first;
        return make_pair(update(u), p.second);
    }
}

node* merge(node *u, node *v) {
    push(u); push(v);
    if (!u || !v) return u ? u : v;    

    if (u->prio > v->prio) {
        u->r = merge(u->r, v);
        return update(u);
    }
    else {
        v->l = merge(u, v->l);
        return update(v);
    }
}

void dfs(node* u, const function<void (node*)> &g) {
    if (u) {
        push(u);

        if (u->l) dfs(u->l, g);
        g(u);
        if (u->r) dfs(u->r, g);
    }
}

void insert (node* &u, int pos, int value) {
    push(u);    
    node* x = update(new node(value));
    
    if (u == nullptr) {
        u = x;
        return;
    }
    
    auto r = split(u, pos);    
    u = merge(merge(r.first, x), r.second);
}

void erase (node* &u, int pos) {
    push(u);
    
    if (!u)
        return;
    
    if (size(u->l) == pos)
        u = merge(u->l, u->r);
    else {
        erase((size(u->l) >= pos) ? u->l : u->r, 
                (size(u->l) >= pos) ? pos : pos - size(u->l) - 1);
        u = update(u);
    }
}

void reverse (node* &u, int l, int r) {
    push(u);

    auto t = split(u, l);
    auto p = split(t.second, r - l + 1);

    if (p.first) p.first->rev ^= true;
    u = merge(merge(t.first, p.first), p.second);
}

// int get (node* u, int i) {
//     if (u) {
//         push(u);

//         if (size(u->l) == i)
//             return u->value;
//         else
//             return get((size(u->l) >= i) ? u->l : u->r, 
//                         (size(u->l) >= i) ? i : i - size(u->l) - 1);
//     }
// }

int64_t query (node* &u, int l, int r) {
    push(u);
    
    auto t = split(u, l);
    auto p = split(t.second, r - l + 1);
    int ans = p.first ? p.first->sum : 0;
    u = merge(merge(t.first, p.first), p.second);

    return ans;
}

void update_interval (node* &u, int l, int r, int x) {
    push(u);
    
    auto t = split(u, l);
    auto p = split(t.second, r - l + 1);
    if (p.first) p.first->lazy = x;
    u = merge(merge(t.first, p.first), p.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if _DEBUG
    freopen("a.in", "r", stdin);
#endif
    node* root = nullptr;
    insert(root, 0, 0);

    int n, q, m;
    cin >> n >> q >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, i + 1, x); 
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 2)
            reverse(root, a, b);
        else {
            int x = query(root, b, b);
            erase(root, b);
            insert(root, a, x);
        }        
    }    

    while (m--) {
        int pos;
        cin >> pos;
        cout << query(root, pos, pos) << " ";
    }
}
