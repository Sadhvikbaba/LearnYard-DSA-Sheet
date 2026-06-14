class MyCalendarTwo {
private :
    map<int, int> mpp;
public:
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        int active = 0;

        mpp[startTime]++;
        mpp[endTime]--;

        for(const auto& [start, end] : mpp) {
            active += end;

            if(active >= 3) {
                mpp[startTime]--;
                if(mpp[startTime] == 0) mpp.erase(startTime);
                mpp[endTime]++;
                if(mpp[endTime] == 0) mpp.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

