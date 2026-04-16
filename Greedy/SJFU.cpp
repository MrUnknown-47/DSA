ong long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        int t=0, wt=0;
        for(int i=0; i<bt.size(); i++){
            wt += t;
            t += bt[i];
        }
        return wt/bt.size();
    }