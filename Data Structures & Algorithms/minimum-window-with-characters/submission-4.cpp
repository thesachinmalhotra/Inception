class Solution {
public:
    string minWindow(string s, string t) {
        int f[128]{}, l=0, missing=t.size(), best=1e9, start=0;

        for(char c:t) f[c]++;

        for(int r=0;r<s.size();r++){
            if(f[s[r]]-- > 0) missing--;

            while(!missing){
                if(r-l+1 < best) best=r-l+1, start=l;
                if(++f[s[l++]] > 0) missing++;
            }
        }

        return best==1e9 ? "" : s.substr(start,best);
    }
};