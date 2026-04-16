int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        int l =0, r=0;
        while(r < s.size() && l < g.size()){
            if(g[l] <= s[r]) l++;
            r++;
        }
        return l;
    }