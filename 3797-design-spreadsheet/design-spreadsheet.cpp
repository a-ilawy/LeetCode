class Spreadsheet {
public:

    unordered_map<string, int> cells;
    Spreadsheet(int rows) {
        // char columnName = 'A';
        // for(int i=0; i<rows; i++){
        //     string cell;
        //     cell += char(columnName + i);
        //     cell += to_string(i);
        //     cells[cell] = 0;
        // }
    }
    
    void setCell(string cell, int value) {
         cells[cell] = value;
    }
    
    void resetCell(string cell) {
         cells[cell] = 0;
    }
    
    int getValue(string formula) {
       formula = formula.substr(1);

        // split by '+'
        size_t pos = formula.find('+');
        string leftOperand = formula.substr(0, pos);
        string rightOperand = formula.substr(pos + 1);

        auto eval = [&](const string& op) {
            if (!op.empty() && isdigit(op[0]))
                return stoi(op);
            return cells.count(op) ? cells[op] : 0;
        };

        return eval(leftOperand) + eval(rightOperand);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */