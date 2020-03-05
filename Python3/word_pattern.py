class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        voc = []
        f = 0
        for i in range(len(str)):
            if str[i] == " " :
                voc.append(str[f:i])
                f = i + 1;
            if i == len(str)-1:
                voc.append(str[f:i+1])
                
        if len(pattern) != len(voc): return False
        
        p_s = {}
        s_p = {}
        
        for i in range(len(pattern)):
            if pattern[i] in p_s and voc[i] != p_s[pattern[i]]: return False
            if voc[i] in s_p and pattern[i] != s_p[voc[i]]: return False
            
            p_s[pattern[i]] = voc[i]
            s_p[voc[i]] = pattern[i]
            
        return True
