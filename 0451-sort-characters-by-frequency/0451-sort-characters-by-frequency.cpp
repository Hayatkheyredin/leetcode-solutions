class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        int n = s.size();
        vector<vector<char>> buckets(n + 1);

        // Place characters into buckets by frequency
        for (auto &p : freq)
            buckets[p.second].push_back(p.first);

        string result = "";
        // Traverse buckets from high to low frequency
        for (int i = n; i > 0; i--) {
            for (char c : buckets[i])
                result.append(i, c);
        }

        return result;
    }
};
