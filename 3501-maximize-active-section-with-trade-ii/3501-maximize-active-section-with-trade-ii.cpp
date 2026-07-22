#include <bits/stdc++.h>
#define pque priority_queue
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using namespace std;
// const int mod = 998244353;
const int mod = 1e9 + 7;
template <typename INT> INT moda(INT a, INT b) {
    INT ans = (a + b) % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}
template <typename INT> INT modm(INT a, INT b) {
    INT ans = (a * b) % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}
template <typename INT> INT fastpow(INT x, ll p, INT def) {
    INT ans = def;
    for (; p; p >>= 1, x = modm(x, x))
        if (p & 1)
            ans = modm(ans, x);
    return ans;
}
bool a93951230 = cin.tie(0)->sync_with_stdio(0);
template <typename T> ostream& operator<<(ostream& l, const vector<T>& r) {
    l << '[';
    for (int i = 0; i < r.size(); i++)
        l << r[i] << ",]"[i == r.size() - 1];
    return l;
}
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// template<class T> using ost = tree<T,null_type, less<T>,
// rb_tree_tag,tree_order_statistics_node_update>; TEMPLATE END

#define N 100001
#define lt l, mid, i << 1
#define rt mid + 1, r, i << 1 | 1
#define tinf int l, int r, int i
int pm[N << 2];
int a[N];
struct {
    void build(int l, int r, int i) {
        if (l == r) {
            pm[i] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(lt), build(rt);
        up(l, r, i);
    }
    void up(tinf) {
        int mid = (l + r) / 2;
        pm[i] = max({a[mid] + a[mid + 1], pm[i << 1], pm[i << 1 | 1]});
    }
    int qrypm(int jl, int jr, tinf) {
        if (jr < l || r < jl)
            return 0;
        if (jl <= l && r <= jr)
            return pm[i];
        int mid = (l + r) / 2;
        int ans = max(qrypm(jl, jr, lt), qrypm(jl, jr, rt));
        if (jl <= mid && mid + 1 <= jr)
            ans = max(ans, a[mid] + a[mid + 1]);
        return ans;
    }
    void add(int ji, int val, tinf) {
        if (ji < l || r < ji)
            return;
        if (l == r) {
            a[ji] += val;
            return;
        }
        int mid = (l + r) / 2;
        add(ji, val, lt), add(ji, val, rt);
        up(l, r, i);
    }
} seg;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& ques) {
        int n = s.size(), q = ques.size();
        vector<int> ans(q);
        int cnt = 0;
        for (char c : s)
            cnt += c == '1';
        //
        vector<int> sep, sepx;
        int last = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                if (s[last] == '0') {
                    sep.emplace_back(i - last);
                    sepx.emplace_back(last);
                }
                last = i;
            }
        }
        if (s[last] == '0') {
            sep.emplace_back(n - last);
            sepx.emplace_back(last);
        }
        int m = sep.size();
        if (!m)
            return vector<int>(q, cnt);
        vector<int> msep(m - 1);
        for (int i = 0; i < m - 1; i++)
            msep[i] = sep[i] + sep[i + 1];
        for (int i = 0; i < m; i++)
            a[i] = sep[i];
        seg.build(0, m - 1, 1);
        //
        vector<int> nez(n, n), prz(n, -1);
        for (int i = 1; i < n; i++) {
            prz[i] = s[i] == '0' ? i : prz[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            nez[i] = s[i] == '0' ? i : nez[i + 1];
        }
        //
        for (int i = 0; i < q; i++) {
            int l = ques[i][0], r = ques[i][1];
            l = nez[l], r = prz[r];
            ans[i] = cnt;
            if (l > r)
                continue;
            int al = lower_bound(all(sepx), l) - begin(sepx);
            if (al == m || sepx[al] != l)
                al--;
            int ar = lower_bound(all(sepx), r) - begin(sepx);
            if (ar == m || sepx[ar] != r)
                ar--;

            int exl = l - sepx[al], exr = sep[ar] - r + sepx[ar] - 1;
            seg.add(al, -exl, 0, m - 1, 1), seg.add(ar, -exr, 0, m - 1, 1);
            ans[i] = cnt + seg.qrypm(al, ar, 0, m - 1, 1);
            seg.add(al, exl, 0, m - 1, 1), seg.add(ar, exr, 0, m - 1, 1);
        }
        return ans;
    }
};