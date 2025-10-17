class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (string op : operations) {
            if (op == "C") {
                record.pop_back();
            } 
            else if (op == "D") {
                record.push_back(record.back() * 2);
            } 
            else if (op == "+") {
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            } 
            else {
                record.push_back(stoi(op));  // convert string to integer
            }
        }

        int sum = 0;
        for (int score : record) {
            sum += score;
        }

        return sum;
    }
};
