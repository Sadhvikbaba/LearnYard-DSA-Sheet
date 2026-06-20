class SubrectangleQueries {
private:
    vector<vector<int>> updates, matrix;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vector<int> temp = {row1, col1, row2, col2, newValue};
        updates.push_back(temp);
    }
    
    int getValue(int row, int col) {
        int n = updates.size() - 1;
        for(int i = n; i >= 0; i--) {
            if(updates[i][0] <= row && row <= updates[i][2] && updates[i][1] <= col && col <= updates[i][3]) return updates[i][4];
        }
        return matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */