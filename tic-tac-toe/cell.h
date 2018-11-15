class Cell {
    bool played = false;
    char val; // X or O
    public:
    bool isPlayed();
    char getVal();
    void setPlayed(bool b);
    void setVal(char c);
};