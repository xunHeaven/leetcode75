//思路链接：https://leetcode.cn/problems/determine-if-two-strings-are-close/solutions/2547579/li-jie-cao-zuo-ben-zhi-jian-ji-xie-fa-py-b18i
class Solution {
public:
    bool closeStrings(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> s_cnt(26);
        for (char c : s) {
            s_cnt[c - 'a']++;
        }

        vector<int> t_cnt(26);
        for (char c : t) {
            t_cnt[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((s_cnt[i] == 0) != (t_cnt[i] == 0)) {
                return false;
            }
        }

        ranges::sort(s_cnt);
        ranges::sort(t_cnt);
        return s_cnt == t_cnt;
    }
};

