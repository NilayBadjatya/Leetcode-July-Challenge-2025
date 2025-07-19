class Solution {
public:

    int findSubfolder(string& a, string& b, int iIdx, int jIdx){
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
            }else{
                break;
            }
        }
        if(i == n && b[j] == '/'){
            return jIdx;
        }else if(j == m && a[i] == '/'){
            return iIdx;
        }
        return -1;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        for(int i = 0; i < n; i++){
            if(folder[i] == "-1") continue;
            for(int j = i+1; j < n; j++){
                if(j == i || folder[j] == "-1") continue;
                int x = findSubfolder(folder[i], folder[j], i, j);
                if(x == -1) continue;
                folder[x] = "-1";
            }
        }
        vector<string> ans;
        for(auto& s : folder){
            if(s == "-1") continue;
            ans.push_back(s);
        }
        return ans;
    }
};
