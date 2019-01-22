#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> a = {"      **      ",
                    "     *  *     ",
                    "    *    *    ",
                    "   * **** *   ",
                    "  * *    * *  ",
                    " ***      *** "};
vector<string> b = {" *******  ",
                    " *      * ",
                    " *     *  ",
                    " *     *  ",
                    " *      * ",
                    " *******  "};
vector<string> c = {"   ******* ",
                    "  * ****** ",
                    " * *       ",
                    " * *       ",
                    "  * ****** ",
                    "   ******* "};
vector<string> d = {" *******   ",
                    " *      *  ",
                    " *   *   * ",
                    " *   *   * ",
                    " *      *  ",
                    " *******   "};
vector<string> e = {" ******* ",
                    " *       ",
                    " ******* ",
                    " ******* ",
                    " *       ",
                    " ******* "};
vector<string> f = {" ******* ",
                    " ******  ",
                    " *       ",
                    " ******  ",
                    " *       ",
                    " *       "};
vector<string> g = {"   ********  ",
                    "  * *******  ",
                    " * *         ",
                    " * *    **** ",
                    "  * ***** *  ",
                    "   ********  "};
vector<string> h = {" ***   *** ",
                    " * *   * * ",
                    " * ***** * ",
                    " * ***** * ",
                    " * *   * * ",
                    " ***   ***  "};

vector<string> i = {" *** ",
                    " * * ",
                    " * * ",
                    " * * ",
                    " * * ",
                    " *** "};
int main() {
    vector<vector<string>> word = {b,i,g,h,e,a,d};
    for (int x = 0; x < 6; ++x) {
        for (auto letter : word) {
            cout << letter[x];
        }
        cout << endl;
    }
}