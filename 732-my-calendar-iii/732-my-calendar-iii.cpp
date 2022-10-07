class MyCalendarThree {
public:
    using ll = long long int;
    map<ll,ll>intervals;
    MyCalendarThree() {
        intervals.clear();
    }
    
    int book(int start, int end) {
        intervals[start]++;
        intervals[end]--;
        ll sum=0,res=0,mx=0;
        for(auto x:intervals){
            sum+=x.second;
            mx=max(mx,sum);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */