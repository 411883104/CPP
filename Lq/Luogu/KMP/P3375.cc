/*
 * @Author       : Outsider
 * @Date         : 2023-02-27 17:06:17
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-02-28 10:47:34
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\KMP\P3375.cc
 */
#include <iostream>
using namespace std;
int nextval[1005];
int main()
{
    string a, b;
    cin >> a >> b;
    size_t i = 1, j = 1, k = 0;
    while (j <= b.size())
    {
        if (k == 0 || b[j - 1] == b[k - 1])
        {
            nextval[++j] = ++k;
        }
        else
        {
            k = nextval[k];
        }
    }
    j = 0;
    while (i <= a.size())
    {
        if (j == 0 || a[i - 1] == b[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
        if (j > b.size())
        {
            cout << i - j + 1 << endl;
            j = nextval[j];
        }
    }

    for (size_t i = 2; i <= b.size() + 1; i++)
    {
        cout << nextval[i] - 1 << " ";
    }
    cout << endl;
}