class Spreadsheet {
public:

    unordered_map<string, int> cells;
    Spreadsheet(int rows) {
        char columnName = 'A';
        for(int i=0; i<rows; i++){
            string cell;
            cell += char(columnName + i);
            cell += to_string(i);
            cells[cell] = 0;
            cout << cell << endl;
        }
    }
    
    void setCell(string cell, int value) {
         cells[cell] = value;
    }
    
    void resetCell(string cell) {
         cells[cell] = 0;
    }
    
    int getValue(string formula) {
        // Remove the '=' at the beginning
        formula = formula.substr(1); // remove '='

        size_t plusPos = formula.find('+');

        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        // Helper lambda to check if the string is a number
        auto isNumber = [](const string& s) {
            return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
        };

        int leftValue = isNumber(left) ? stoi(left) : cells[left];
        int rightValue = isNumber(right) ? stoi(right) : cells[right];

        return leftValue + rightValue;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */