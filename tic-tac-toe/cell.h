class Cell {
    bool played = false;
    char val; 
    
    public:
    bool isPlayed();
    char getVal();
    void setPlayed(bool b);
    void setVal(char c);
};