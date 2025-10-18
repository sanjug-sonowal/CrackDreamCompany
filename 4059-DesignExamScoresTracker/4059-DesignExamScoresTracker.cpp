// Last updated: 18/10/2025, 08:58:49
class ExamTracker {
    private:
    vector<pair<int, long long>> records;
    long long totalSum;
public:
    ExamTracker():totalSum(0) { }
    
    void record(int time, int score) {
        totalSum += score;
        records.push_back({time, totalSum});
    }
    
    long long totalScore(int startTime, int endTime) {
        if (records.empty()) return 0;
        
        auto startIt = lower_bound(records.begin(), records.end(), make_pair(startTime, 0LL));
        auto endIt = upper_bound(records.begin(), records.end(), make_pair(endTime, LLONG_MAX));
        
        if (startIt == records.end() || startIt->first > endTime) return 0;
        
        long long endSum = (endIt == records.end()) ? totalSum : (endIt - 1)->second;
        long long startSum = (startIt == records.begin()) ? 0 : (startIt - 1)->second;
        
        return endSum - startSum;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */