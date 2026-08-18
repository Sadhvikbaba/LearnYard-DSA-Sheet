class TopVotedCandidate {
    vector<int> time, arr;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), maxi = 0, ans = -1;
        vector<int> votes(n);

        for(int i = 0; i < n; i++) {
            votes[persons[i]]++;
            if(votes[persons[i]] >= maxi) {
                maxi = votes[persons[i]];
                ans = persons[i];
            }
            arr.push_back(ans);
        }

        time = times;
    }
    
    int q(int t) {
        int it = upper_bound(time.begin(), time.end(), t) - time.begin() - 1;

        return arr[it];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */