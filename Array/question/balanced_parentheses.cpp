#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define MAX_SIZE 100
 
void _printParenthesis(int pos, int n, int open, int close);
 
// Wrapper over _printParenthesis()
void printParenthesis(int n)
{
    if (n > 0)
        _printParenthesis(0, n, 0, 0);
    return;
}
 
void _printParenthesis(int pos, int n, int open, int close)
{
    static char str[MAX_SIZE];
    std::cout << pos;
    if (close == n) {
        std::cout << str << std::endl;
        std::cout << pos;
        return;
    }
    else {
        if (open > close) {
            str[pos] = '}';
            _printParenthesis(pos + 1, n, open, close + 1);
        }
 
        if (open < n) {
            str[pos] = '{';
            _printParenthesis(pos + 1, n, open + 1, close);
        }
    }
}
void generatePArenthese(vector<string> &v, int n, string s, int open, int close)
{
    if (open == n && close == n)
    {
        v.push_back(s);
        return;
    }
    if (open < n)
    {
        generatePArenthese(v, n, s + "(", open + 1, close);
    }
    if (close < open)
    {
        generatePArenthese(v, n, s + ")", open, close + 1);
    }
}
int main()
{
    int n = 15;
    printParenthesis(n);
    // auto start = high_resolution_clock::now();
    // int n = 2;
    // vector<string> v;
    // generatePArenthese(v, n, "", 0, 0);
    // for (auto i : v)
    // {
    //     cout << i << endl;
    // }

    // auto stop = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop - start);

    // cout << "\n\n\n\n\\n\n\\n\n"
    //      << (duration.count() / 1000000) << endl;
    // cout << "complete";
    return 0;
}