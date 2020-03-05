class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> voc;
        int f = 0;
        string c = "";
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') {
                voc.push_back(c);
                f = i + 1;
                c = "";
                continue;
            }
            c += str[i];
            if(i == str.size()-1) voc.push_back(c);
        }
                
        if(pattern.size() != voc.size()) return false;
        
        map<char, string> p_s = {};
        map<string, char> s_p = {};
        
        for(int i = 0; i < pattern.size(); i++) {
            if(p_s.find(pattern[i]) != p_s.end() && voc[i] != p_s[pattern[i]]) 
                return false;
            if(s_p.find(voc[i]) != s_p.end() && pattern[i] != s_p[voc[i]]) 
                return false;
            
            p_s[pattern[i]] = voc[i];
            s_p[voc[i]] = pattern[i];
        }
            
        return true;
    }
};
