struct Cla{
    struct Edge{
        int t, u;
        Edge *nx, *op;
    }*e[N], mem[E], *C;
    int n, S, T;
    int vh[N], h[N];

    void init(int num){
        n = num;
        C = mem;
        rep(i, n) e[i] = NULL;
    }

    void add_edge(int u, int v, int c){
        C->t = v, C->u = c, C->nx = e[u], e[u] = C++;
        C->t = u, C->u = 0, C->nx = e[v], e[v] = C++;
        e[u]->op = e[v];
        e[v]->op = e[u];
    }

    int aug(int p, int m){
        if (p == T) return m;
        int d = m;
        for(Edge *i = e[p]; i; i = i->nx){
            if (i->u && h[p] == h[i->t] + 1){
                int f = aug(i->t, min(i->u, d));
                i->u -= f, i->op->u += f, d-= f;
                if (h[S] == n || !d) return m - d;
            }
        }
        int w = d < m ? min(n, h[p] + 2) : n;
        for(Edge *i = e[p]; i; i = i->nx){
            if (i->u) w = min(w, h[i->t] + 1);
        }
        ++vh[w];
        --vh[h[p]] ? h[p] = w : h[S] = n;
        return m - d;
    }

    int maxflow(int s, int t){
        S = s, T = t;
        rep(i, n) vh[i] = 0, h[i] = 0;
        vh[0] = n;
        int ret = 0;
        while(h[S] != n) ret += aug(S, INT_MAX);
        return ret;
    }
}graph;
