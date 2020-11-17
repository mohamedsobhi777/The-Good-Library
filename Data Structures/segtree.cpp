struct stree
{
        int sz = 0;
        vector<int> tree, lazy;
        stree() {}
        void init(int x)
        {
                sz = x;
                tree = lazy = vector<int>(x * 4, 0);
        }
        void update(int node, int L, int R, int l, int r, int v)
        {
                if (l > R || r < L)
                        return;
                if (L >= l && R <= r)
                        return void(lazy[node] += v);
                int mid = (L + R) >> 1;
                update(node * 2 + 1, L, mid, l, r, v);
                update(node * 2 + 2, mid + 1, R, l, r, v);
                tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2] + (R - L + 1) / 2 * (lazy[node * 2 + 1] + lazy[node * 2 + 2]);
        }
        int query(int node, int L, int R, int l, int r)
        {
                if (l > R || r < L)
                        return 0;
                if (L >= l && R <= r)
                        return tree[node] + lazy[node] * (R - L + 1);
                int mid = (L + R) >> 1;
                int s1 = query(node * 2 + 1, L, mid, l, r);
                int s2 = query(node * 2 + 2, mid + 1, R, l, r);
                return s1 + s2 + lazy[node] * (min(R, r) - max(l, L) + 1);
        }
        inline int qry(int l, int r) { return query(0, 1, sz, l, r); }
        inline void upd(int l, int r, int v) { update(0, 1, sz, l, r, v); }
};
