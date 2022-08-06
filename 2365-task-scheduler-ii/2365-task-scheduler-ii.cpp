class Solution {
public:
    using ll = long long int;
    void printQ(priority_queue< pair<ll,ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq){
        cout<<"current q: ";
        while(!pq.empty()){
                        auto u = pq.top();
                        pq.pop();
                        cout<<u.second<<" ase list a. time "<<u.first<<endl;
                    }
        cout<<"end\n";
    }
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        priority_queue< pair<ll,ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
        
        ll curr=0;
        map<ll,ll> last_executed;
        for(int i=0;i<tasks.size();i++){
            //printQ(pq);
            if(last_executed[tasks[i]]){
                
                if(curr - last_executed[tasks[i]] >= space ){
                    //cout<<"bug\n";
                    last_executed[tasks[i]] = ++curr;
                    //cout<<"executing1 "<<tasks[i]<<" at time "<<curr<<endl;
                }
                else{ // ekhon kora jabe na
                    // onno kono available ase naki dekhi
                    pq.push({last_executed[tasks[i]]+space, tasks[i]});
                    //cout<<"nai\n";
                    //cout<<"top element "<<pq.top().first<<" "<<pq.top().second<<" current time "<<curr<<endl;
                    while(!pq.empty()){
                        auto u = pq.top();
                        pq.pop();
                        //cout<<u.second<<" ase list a. time "<<u.first<<endl;
                        curr=u.first;
                        last_executed[u.second] = ++curr;
                        //cout<<"executing1 "<<u.second<<" at time "<<curr<<endl;
                    }
               }
            }
            else{
                
                last_executed[tasks[i]] = ++curr;
                //cout<<"executing2 "<<tasks[i]<<" at time "<<curr<<endl;
            }
        }
        while(!pq.empty()){
                        auto u = pq.top();
                        pq.pop();
                        
                        curr=u.first;
                        last_executed[u.second] = ++curr;
        }
        //cout<<endl;
        return curr;
    }
};