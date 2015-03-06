const int kMaxN = 55005;
const int kMaxM = kMaxN*kMaxN;
struct SAP{
    //S -> source, T -> sink 
    //n -> |V|, cnt -> 2 * |E|
    int S, T, n, cnt;
    int f[kMaxM], adj[kMaxM], next[kMaxM];
    int g[kMaxN], last[kMaxN], h[kMaxN], vh[kMaxN];

    void init(int _n){
        n = _n;
        cnt = 0;
        for (int i = 0; i < n; i++) g[i] = -1;
    }

    void addedge(int x, int y, int limit){
        f[cnt] = limit;
        adj[cnt] = y;
        next[cnt] = g[x];
        g[x] = cnt++;

        f[cnt] = 0;
        adj[cnt] = x;
        next[cnt] = g[y];
        g[y] = cnt++;
    }

    void BFS(int T){
        for (int i = 0; i < n; i++){
            h[i] = -1;
            vh[i] = 0;
        }
        vh[h[T] = 0] = 1;
        queue<int> q;
        q.push(T);
        while (!q.empty()){
            int node=q.front(); q.pop();
            for (int p = g[node]; p != -1; p = next[p]){
                /* p % 2 == 1 indicate reverse edge
                 * h[adj[p]] == -1 indicate the node isn't label
                */
                if ((p&1) && h[adj[p]] == -1){ 
                    ++vh[h[adj[p]] = h[node] + 1];
                    q.push(adj[p]);
                }
            }
        }
    }

    int dfs(int node, int add){
        if (node == T) return add;
        int minh = n, p = last[node];
        do{
            if (f[p] > 0){
                int y = adj[p];
                if (h[node] == h[y] + 1){
                    int temp = dfs(y, min(add, f[p]));
                    if (temp > 0){
                        f[p] -= temp;
                        f[p ^ 1] += temp;
                        last[node] = p;
                        return temp;
                    }
                }
                if (h[S] >= n) return 0;
                minh = min(minh, h[y] + 1);
            }
            p = next[p];
            if (p == -1) p = g[node];
        } while (p != last[node]);

        if (--vh[h[node]] == 0) h[S] = n;
        ++vh[h[node] = minh];
        return 0;
    }

    int maxflow(int _S, int _T){
        S = _S, T = _T;
        if (g[S] == -1){
            //the graph not connected with source
            return -1;
        }

        /* make label with BFS, sometime the effect is good 
        BFS(T);
        for (int i = 0; i < n; i++){
            last[i] = g[i];
        }
        */
        
        //don't make label with BFS
        for (int i = 0; i < n; i++){
            h[i] = vh[i] = 0;
            last[i] = g[i];
        }
        //end

        int flow = 0;
        while (h[S] < n) flow += dfs(S, INF);
        return flow;
    }
} solver;
