class Solution {
public:
    string minWindow(string s,string t) {
        int a[128]{},l=0,n=t.size(),p,q=1e9;
        for(char c:t)a[c]++;
        for(int r=0;r<s.size();r++){
            if(a[s[r]]-->0)n--;
            while(!n){
                if(r-l+1<q)q=r-l+1,p=l;
                if(++a[s[l++]]>0)n++;
            }
        }
        return q<1e9?s.substr(p,q):"";
    }
};