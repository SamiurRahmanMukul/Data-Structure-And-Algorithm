#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int m = 1e9 + 7;

class Solution {
public:
    unordered_map<int, unordered_map<lli, int> > dp;
    lli add(lli a, lli b) {
        return ((a % m) + (b % m)) % m;
    }

    int help(int idx, string& s, lli num, int k) {
        if (idx >= s.size())
            return 1;
        if (dp.count(idx) && dp[idx].count(num))
            return dp[idx][num];
        int ret = 0;
        if (num >= 1 && num <= k && s[idx] != '0') {
            ret = add(help(idx, s, 0, k), ret);
        }
        if (num * 10 + (s[idx] - '0') <= k) {
            ret = add(help(idx + 1, s, num * 10 + (s[idx] - '0'), k),
                      ret);
        }
        return dp[idx][num] = ret;
    }

    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<lli> ans(n + 1);
        ans[0] = 1;
        s = " " + s;
        string ks = to_string(k);
        for (lli i = 1; i <= n; i++) {
            lli cnt = 1;
            string temp = "";
            for (lli j = i; j >= 1 && cnt <= 10; j--, cnt++) {
                temp = s[j] + temp;
                if (s[j] == '0')
                    continue;
                if (temp.size() > ks.size())
                    break;
                lli val = stol(temp);
                if (val >= 1 && val <= k) {
                    ans[i] = add(ans[i], ans[j - 1]);
                }
            }
        }

        return ans[n];
    }
};

main() {
    Solution ob;
    cout << (ob.numberOfArrays("1318",2000));

    return 0;
}
