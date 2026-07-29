# include<iostream>
# include<vector>
using namespace std;

const long long Mode=998244353;

/*
 * down[u]：
 * 完全位于以 u 为根的子树中，并且必须包含 u 的连通点集数量。
 *
 * up[u]：
 * 切断 u 与父亲之间的边后，在父亲所在的一侧，
 * 必须包含父亲、因而可以通过父亲与 u 相连的连通点集数量。
 * 根结点没有父亲，所以 up[1] = 0。
 *
 * ways[u]：
 * 整棵树中所有包含 u 的连通点集数量。
 * 最终 a[u] 会在这些点集中各贡献一次。
 */
vector<int> up;
vector<int> down;
vector<int> ways;

// 无向树的邻接表：edge[u] 保存所有与 u 直接相连的结点。
vector<vector<int>> edge;

/*
 * 第一遍 DFS：从儿子向父亲计算 down。
 *
 * parent 表示 u 是从哪个结点走过来的。
 * 因为每条无向边会在邻接表中保存两次，所以遍历时必须跳过 parent，
 * 否则会沿原路返回，形成无限递归。
 */
void dfs1(int u,int parent)
{
    // 所有儿子方向都不选择时，仍有只选择 {u} 这一种方案。
    down[u]=1;
    for(int v:edge[u])
    {
        if(v==parent) continue;

        // 先递归计算儿子，返回后才能使用 down[v]。
        dfs1(v,u);

        /*
         * 对儿子 v 所在的方向有两类选择：
         * 1：完全不选择 v 的子树；
         * down[v]：选择一个包含 v 的连通点集。
         *
         * 不同儿子方向相互独立，因此使用乘法原理。
         */
        down[u]=1LL*down[u]*(1+down[v])%Mode;
    }
}

/*
 * 第二遍 DFS：从父亲向儿子传递 up，同时计算 ways。
 *
 * 对于儿子 v，up[v] 只能包含 v 子树之外的部分：
 * - u 以及 u 的父亲方向；
 * - v 的所有兄弟方向。
 *
 * 不能包含 v 自己的方向，因为该方向之后由 down[v] 负责。
 */
void dfs2(int u,int parent)
{
    // 只收集真正的儿子，不把 parent 混入前后缀积。
    vector<int> children;
    for(int v:edge[u]){
        if(v!=parent) children.push_back(v);
    }

    int k=children.size();
    vector<long long> pre(k+1,1),suf(k+1,1);

    /*
     * 设 F[i] = 1 + down[children[i]]。
     *
     * pre[i] 表示 F[0] 到 F[i-1] 的乘积，即“前 i 个”的乘积，
     * 所以 pre[i] 不包含下标 i。
     *
     * suf[i] 表示 F[i] 到 F[k-1] 的乘积，
     * 所以 suf[i] 包含下标 i。
     *
     * 因此 pre[i] * suf[i+1] 恰好包含 i 左右两边，
     * 但不包含 children[i] 自己。
     */

    // 构造前缀积。
    for(int i=0;i<k;i++){
        int v=children[i];
        pre[i+1]=pre[i]*(1+down[v])%Mode;
    }

    // 构造后缀积。
    for(int i=k-1;i>=0;i--){
        int v=children[i];
        suf[i]=suf[i+1]*(1+down[v])%Mode;
    }

    /*
     * down[u] 负责 u 的所有儿子方向。
     * 父亲方向可以完全不选（1 种），也可以选择 up[u] 中的一种。
     */
    ways[u]=1LL*down[u]*(1+up[u])%Mode;

    for (int i = 0; i < k; i++) {
        int v = children[i];

        /*
         * 排除 v 自己的方向，只保留 v 的所有兄弟方向。
         * pre[i] 负责左边，suf[i+1] 负责右边。
         */
        long long exceptV =
            pre[i] * suf[i + 1] % Mode;

        /*
         * 从 v 看，父亲侧由两部分组成：
         * 1 + up[u]：u 的父亲方向不选，或者选择一个合法方案；
         * exceptV：v 的所有兄弟方向分别不选或选择。
         *
         * u 本身必须选择，才能把这些方向与 v 连接起来。
         * 选择 u 本身只有一种情况，所以公式中不需要额外的因子。
         */
        up[v] =
            1LL * (1 + up[u]) * exceptV % Mode;

        // 将计算好的父亲侧信息继续传给 v 的儿子。
        dfs2(v, u);
    }
}

int main()
{
    int n;
    cin>>n;
    // 权值可能较大，用 long long 保存更稳妥。
    vector<long long> a(n+1);
    up.resize(n+1,0);
    down.resize(n+1,0);
    ways.resize(n+1,0);
    edge.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    /*
     * 第一遍 DFS：
     * 计算每个结点的 down，也就是只考虑子树方向时的方案数。
     */
    dfs1(1,0);

    /*
     * 根结点没有父亲侧，所以 up[1] = 0。
     *
     * 第二遍 DFS：
     * 利用已经算好的 down，把父亲侧的信息向下传递，
     * 并得到每个结点的 ways。
     */
    up[1] = 0;
    dfs2(1, 0);

    /*
     * 每一个包含结点 u 的连通点集，都会让 a[u] 对答案贡献一次。
     * 一共有 ways[u] 个连通点集包含 u，
     * 所以结点 u 的总贡献为 a[u] * ways[u]。
     *
     * 把所有结点的贡献相加，就等价于：
     * 对所有连通点集，分别计算其中所有结点的权值和，再将它们累加。
     */
    long long ans=0;
    for(int u=1;u<=n;u++)
    {
        ans=(ans+a[u]%Mode*ways[u])%Mode;
    }

    cout<<ans<<'\n';

    return 0;
}
