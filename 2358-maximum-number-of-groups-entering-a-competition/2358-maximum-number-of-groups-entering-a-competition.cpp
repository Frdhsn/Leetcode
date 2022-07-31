class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        
        int pr_sz = 0,res=0,pr_sum = 0;
        int curr_sz = 0,curr_sum = 0;
        
        for(int i=0;i<grades.size();i++){
            curr_sz++;
            curr_sum+=grades[i];
            if(curr_sz>pr_sz && curr_sum>pr_sum){
                res++;
                pr_sz = curr_sz;
                pr_sum = curr_sum;
                curr_sz=0;
                curr_sum=0;
            }
        }
        return res;
    }
};