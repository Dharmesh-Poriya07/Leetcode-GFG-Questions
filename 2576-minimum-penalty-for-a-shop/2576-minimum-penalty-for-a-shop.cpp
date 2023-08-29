class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int total_open = 0;

        for (int i = 0; i < n; i++)  total_open += (customers[i] == 'Y' ? 1 : 0);

        int min_p = n;
        int hour = n;
        int curr_open = 0;
        int curr_close = 0;

        for (int h = 0; h <= n; h++) {
            int y_remaining = total_open - curr_open;
            int curr_pen = y_remaining + curr_close;

            if (curr_pen < min_p) {
                hour = h;
                min_p = curr_pen;
            }

            if (h < n and customers[h] == 'N') curr_close++;
            if (h < n and customers[h] == 'Y') curr_open++;
        }

        return hour;
    }
};