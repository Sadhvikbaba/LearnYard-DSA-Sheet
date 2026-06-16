class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int capA = capacityA, capB = capacityB, i = 0, j = plants.size() - 1, ans = 0;

        while(i < j) {
            if(capA < plants[i]) {
                capA = capacityA;
                ans++;
            }
            capA -= plants[i];
            

            if(capB < plants[j]) {
                capB = capacityB;
                ans++;
            }
            capB -= plants[j];

            i++;
            j--;

            if(i == j) {
                int maxi = max(capA, capB);
                if(maxi < plants[i]) ans++;
            }
        }
        return ans;
    }
};