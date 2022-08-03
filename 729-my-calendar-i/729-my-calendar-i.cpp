// O(n^2)
class MyCalendar {
public:
    vector< pair<int,int> > table;
    MyCalendar() {
        table.clear();
    }
    
    bool book(int start, int end) {
        end--;
        int cnt=0;
        for(int i=0;i<table.size();i++){
            // cout<<table[i].first<<","<<table[i].second<<"]"<<endl;
            if(end <table[i].first or   start>table[i].second){
                cnt++; 
            }
        }
        // cout<<start<<","<<end<<": "<<cnt<<endl;
        
        if(cnt !=table.size()) return 0;
        table.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */