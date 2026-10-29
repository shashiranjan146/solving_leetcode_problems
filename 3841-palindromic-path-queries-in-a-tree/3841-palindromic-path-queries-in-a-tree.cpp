class Solution {
public:
     vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy;
    vector<int> head, pos, inv;
    vector<int> bit;
    int timer = 0;

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void dfs1(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        heavy[u] = -1;

        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs1(v, u);
            sz[u] += sz[v];

            if (sz[v] > maxSize) {
                maxSize = sz[v];
                heavy[u] = v;
            }
        }
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = timer;
        inv[timer++] = u;

        if (heavy[u] != -1)
            dfs2(heavy[u], h);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            dfs2(v, v);
        }
    }

    void add(int i, int val) {
        for (; i < (int)bit.size(); i += i & -i)
            bit[i] ^= val;
    }

    int queryBIT(int i) {
        int res = 0;

        for (; i > 0; i -= i & -i)
            res ^= bit[i];

        return res;
    }

    void rangeXor(int l, int r, int val) {
        add(l + 1, val);
        add(r + 1, val);
    }

    int getMask(int u) {
        return queryBIT(pos[u] + 1);
    }

    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]])
                u = parent[head[u]];
            else
                v = parent[head[v]];
        }

        return depth[u] < depth[v] ? u : v;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        parent.resize(n);
        depth.assign(n, 0);
        sz.resize(n);
        heavy.resize(n);
        head.resize(n);
        pos.resize(n);
        inv.resize(n);
        dfs1(0, -1);
        dfs2(0, 0);
        vector<int> pref(n, 0);
        for (int u : inv) {
            pref[u] = mask(s[u]);

            if (parent[u] != -1)
                pref[u] ^= pref[parent[u]];
        }
        bit.assign(n + 2, 0);
        for (int u = 0; u < n; u++)
            rangeXor(pos[u], pos[u] + 1, pref[u]);

        vector<bool> ans;
        for (string& q : queries) {
            string op;
            int u, v;
            stringstream ss(q);
            ss >> op >> u;
            if (op == "update") {
                char c;
                ss >> c;
                int delta = mask(s[u]) ^ mask(c);
                if (delta != 0) {
                    rangeXor(pos[u], pos[u] + sz[u], delta);
                    s[u] = c;
                }
            } 
            else {
                ss >> v;
                int w = lca(u, v);
                int pathMask =
                    getMask(u) ^ getMask(v) ^ mask(s[w]);
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};