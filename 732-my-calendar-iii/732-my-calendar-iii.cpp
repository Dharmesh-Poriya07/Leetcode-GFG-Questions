class MyCalendarThree {
private:
    unordered_map<int, int> values,previous;

public:
    MyCalendarThree() {}

    void update(int start, int end, int left, int right, int index) {
        if (start > right or end < left)
            return;
        if (left >= start && right <= end) 
            previous[index]++,values[index]++;
        else {
            int mid = (left + right) / 2;
            update(start, end, left, mid,2*index);
            update(start, end, mid + 1, right, index * 2 + 1);
            values[index] = previous[index] + max(values[index * 2], values[index * 2 + 1]);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 1, 1000000000, 1);
        return values[1];
    }
};