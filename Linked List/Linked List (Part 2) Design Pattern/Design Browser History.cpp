class BrowserHistory {
private:
    vector<string> list;
    int ind = 0;
public:
    BrowserHistory(string homepage) {
        list.push_back(homepage);
    }
    
    void visit(string url) {
        list.erase(list.begin() + ind + 1, list.end());
        list.push_back(url);
        ind++;
    }
    
    string back(int steps) {
        if(ind < steps) {
            ind = 0;
            return list[0];
        }

        ind -= steps;
        return list[ind];
    }
    
    string forward(int steps) {
        if(steps > list.size() - ind - 1) {
            ind = list.size() - 1;
            return list[ind];
        }
        ind += steps;
        return list[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */