class MyCalendarTwo {
public:
    using ll = long long int;
    
    map<ll,int> intervals;
    MyCalendarTwo() {
        
        intervals.clear();
    }
    
    bool book(int start, int end) {
        intervals[start]++;
        intervals[end]--;
        ll sum=0;
        int res=0;
        for(auto x:intervals){
            sum+=x.second;
            if( sum >= 3){
                
                intervals[start]--;
                intervals[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */