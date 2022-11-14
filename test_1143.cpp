#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> b(text1.size() + 1, vector<int>(text2.size() + 1, 0)); //为了避免进行初始化，直接用size（）+1
    for (size_t i = 0; i < text1.size(); i++)
    {
        /* code */
        for (size_t j = 0; j < text2.size(); j++)
        {
            /* code */
            if (text1[i] == text2[j])
            {
                /* code */
                b[i + 1][j + 1] = b[i][j] + 1;
            }
            else
            {
                b[i + 1][j + 1] = max(b[i + 1][j], b[i][j + 1]);
            }
        }
    }
    return b[text1.size()][text2.size()];
}

int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2);
}