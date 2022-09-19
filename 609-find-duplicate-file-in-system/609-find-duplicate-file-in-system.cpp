class Solution {
public:
    void mapping(string x,map<string,vector<string>> &mp){
        stringstream ss(x);
        string directory_path,file_name,content;
        ss>>directory_path;
        directory_path+="/";
        while(ss>>file_name){
            content.clear();
            file_name.pop_back();
            while(file_name.back()!='('){
                content.push_back(file_name.back());
                file_name.pop_back();
            }
            file_name.pop_back();
            reverse(content.begin(),content.end());
            mp[content].push_back(directory_path+file_name);
        }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>res;
        map<string,vector<string>> mp;
        for(auto x:paths){
            mapping(x,mp);
        }
        
        for(auto x:mp){
            if(mp[x.first].size()>1){
                vector<string>tmp;
                for(auto y:mp[x.first]){
                    tmp.push_back(y);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};