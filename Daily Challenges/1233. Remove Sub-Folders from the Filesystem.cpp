class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string> st;
        for(auto fold: folder ){
            string temp = "";
            int flag = 1;
            for(auto i:fold){
                if(i=='/'){
                    if(st.find(temp)!=st.end()){
                        flag = 0;
                        break;
                    }
                }
                temp+=i;
            }
            if(flag){
                st.insert(temp);
            }
        }
        vector<string> ans(st.begin(),st.end());

        return ans;
    }
};