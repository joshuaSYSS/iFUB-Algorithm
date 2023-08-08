#include <bits/stdc++.h>
using namespace std; //名前空間の宣言
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::ios;
using std::stringstream;
using std::chrono::duration_cast;
using namespace std::chrono;
using ll = long long; using ld = long double;
using ull = unsigned long long; using str = string;
using bl = bool; using ch = char;
using cd = complex<ld>;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<vector<ll>> vl2;
typedef vector<str> vs;
typedef map<ll, ll> mll;
#define LL_MAX 9223372036854775807
#define up(initial, n, step) for(ll i = (ll)(initial);i < (ll)(n);i+=(ll)(step))
#define up2(initial, n, step) for(ll j = (ll)(initial);j < (ll)(n);j+=(ll)(step))
#define up3(initial, n, step) for(ll k = (ll)(initial);k < (ll)(n);k+=(ll)(step))
#define down(initial, n, step) for(ll i = (ll)(initial) - 1;i >= (ll)(n);i-=(ll)(step))
#define stop return EXIT_SUCCESS;
#define toStr(s) to_string((s))
#define foreach(a, v) for(auto& a : v)
#define _m_ int main(void)
const str alphabet = "abcdefghijklmnopqrstuvwxyz";
const str upAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ld PHI = (1 + sqrt(5)) / 2;
const ll Mod = 998244353;
const ll Mod2 = pow(10, 9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);

vl2 graph;
//O(M * LOG(N) + N)
ll maxNode(vl2 edges) {
    ll len = edges.size();
    ll n = graph.size();
    mll m;
    up(0, len, 1) {
        // Storing the degree for each node
        m[edges[i][0]]++;
        m[edges[i][1]]++;
    }
    // maxi and mini variables to store
    // the maximum and minimum degree
    ll maxi = 0, mini = n;
    up(1, n + 1, 1) {
        maxi = max(maxi, m[i]);
        mini = min(mini, m[i]);
    }
    up(1, n + 1, 1) {
        if (m[i] == maxi)
            return i;
    }
};

//Check are 2
bl BFS(vl2& adj, ll a, ll b){
    list<ll> queue;
    ll v = graph.size();
    vl visited(v, 0), dist(v, INT_MAX), pred(v, -1);
    visited[a] = 1, dist[a] = 0, queue.push_back(a);
    while (!queue.empty()) {
        ll u = queue.front();
        queue.pop_front();
        up(0, (ll)adj[u].size(), 1) {
            if (!visited[adj[u][i]]) {
                visited[adj[u][i]] = 1;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
                if (adj[u][i] == b) return 1;
            }
        }
    }
    return 0;
}

//Shortest Distance d(a, b)
ll dist(vl2 &adj, ll a, ll b) {
    ll v = graph.size(), crawl = b;
    vl pred(v), dist(v), path;
    if (!BFS(adj, a, b)) return 0;
    path.push_back(crawl);
    while (pred[crawl] != -1) path.push_back(pred[crawl]), crawl = pred[crawl];
    return dist[b];
}

//Middle Node
vl middle(ll a, ll b) {
    ll v = graph.size(), crawl = b;
    vl pred(v), dist(v), path;
    path.push_back(crawl);
    while (pred[crawl] != -1) path.push_back(pred[crawl]), crawl = pred[crawl];
    return path;
}

//eccentricity of point a
ll ecc(vl2& adj, ll a) {
    ll dt = 0;
    up(1, (ll)graph.size(), 1) if(i != a) dt = max(dt, dist(adj, a, i));
    return dt;
}

//Return lowerb and u
pair<ll, ll> sweep4(vl2 edges, ll r1) {
    ll a1 = 0, a1Dist = 0;
    up(1, (ll)graph.size(), 1) {
        ll d = dist(edges, r1, i);
        if (d > a1Dist)
            a1Dist = d,
            a1 = i;
    }
    ll b1 = 0, b1Dist = 0;
    up(1, (ll)graph.size(), 1) {
        ll d = dist(edges, a1, i);
        if (d > b1Dist)
            b1Dist = d,
            b1 = i;
    }

    vl m = middle(a1, b1);
    r1 = m[m.size() / 2];
    ll a2 = a1;
    a1 = 0, a1Dist = 0;
    up(1, (ll)graph.size(), 1) {
        ll d = dist(edges, r1, i);
        if (d > a1Dist)
            a1Dist = d,
            a1 = i;
    }
    b1 = 0, b1Dist = 0;
    up(1, (ll)graph.size(), 1) {
        ll d = dist(edges, a1, i);
        if (d > b1Dist)
            b1Dist = d,
            b1 = i;
    }

    vl m = middle(a1, b1);
    ll u = m[m.size() / 2];
    ll lowerb = max(ecc(edges, a1), ecc(edges, a2));
    return { lowerb, u };
};

//In general, let F[i](u) be the fringe set of nodes at distance i from u (note that F(u) = F[ecc(u)](u)) and let
//B[i](u) = max[z∈Fi(u)] ecc(z) be the maximum eccentricity among these nodes
//
//Now, according to my understanding, B[i](u) is a function finding the max ecc and
//F[i](u) is a function finding all nodes v that d(u, v) = i. Correct me if I'm incorrect. I can't find any precise explanation online.
ll B(vl2& edges, ll i, ll u) {
    //TO-DO
}

//OUTPUT: A value M such that D − M ≤ k
ll iFUB(vl2& edges, ll u, ll l, ll k) {
    ll i = ecc(edges, u);
    ll lb = max(i, l);
    ll ub = 2 * i;
    while (ub - lb > k) {
        ll b = B(edges, i, u);
        if (max(lb, b) > 2 * (i - 1)) {
            return max(lb, b);
        }
        else {
            lb = max(lb, b);
            ub = 2 * (i - 1);
        }
        i--;
    }
}
_m_{
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
//Standard get input for graph stuff. Remember its undirected.
ll nodes = get(), edges = get();
graph.resize(nodes + 1); //graph[0] is empty
vl2 ed(edges, vl(2));
up(0, edges, 1) {
    ed[i][0] = get(),
        ed[i][1] = get(),
        graph[ed[i][0]].push_back(ed[i][1]),
        graph[ed[i][1]].push_back(ed[i][0]);
}
ll maxNd = maxNode(ed);
pair<ll, ll> sweep = sweep4(ed, maxNd);
cout << iFUB(ed, sweep.second, sweep.first, 0) << '\n';
stop 
}
