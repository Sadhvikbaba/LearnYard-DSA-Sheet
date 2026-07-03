struct Robot {
    int pos;
    int health;
    char dir;
    int idx;

    Robot() {};
    Robot(int pos, int health, char dir, int idx) : pos(pos), health(health), dir(dir), idx(idx) {};
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);

        vector<int> st;

        for(int i = 0; i < n; i++) {
            robots[i] = Robot(positions[i], healths[i], directions[i], i);
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) { return a.pos < b.pos;});
        
        for(int i = 0; i < n; i++) {
            if(robots[i].dir == 'R') st.push_back(i);
            else {
                Robot &curr = robots[i];
                while(!st.empty() && curr.health) {
                    Robot &temp = robots[st.back()];

                    if(temp.health > curr.health) {
                        temp.health--;
                        curr.health = 0;
                        break;
                    } else if(temp.health < curr.health) {
                        st.pop_back();
                        curr.health--;
                        temp.health = 0;
                    } else {
                        curr.health = 0;
                        temp.health = 0;
                        st.pop_back();
                        break;
                    }
                }
            }
        }

        vector<int> ans, alive(n, 0);
        for(const Robot &r : robots) alive[r.idx] = r.health;

        for(const int& it : alive) {
            if(it) ans.emplace_back(it);
        }
        return ans;
    }
};