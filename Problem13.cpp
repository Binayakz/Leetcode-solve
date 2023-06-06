#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<char> romanChar{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> intValue{1, 5, 10, 50, 100, 500, 1000};

    string romanValue;
    cin >> romanValue;
    int result = 0;

    if (romanValue.size() == 1)
    {
        char c1 = romanValue[0];
        int idx1 = find(romanChar.begin(), romanChar.end(), c1) - romanChar.begin();
        result = intValue[idx1];
    }

    else
    {
        char c2;
        int idx2;
        for (int i = 0; i < romanValue.size(); i++)
        {
            char c1 = romanValue[i];
            int idx1 = find(romanChar.begin(), romanChar.end(), c1) - romanChar.begin();
            if ((i + 1) >= romanValue.size())
            {
                result += intValue[idx1];
                break;
            }
            c2 = romanValue[i + 1];
            idx2 = find(romanChar.begin(), romanChar.end(), c2) - romanChar.begin();

            if (idx1 < idx2)
            {
                result += (intValue[idx2] - intValue[idx1]);
                i++;
            }
            else
            {
                result += intValue[idx1];
            }
        }
    }

    cout << result << endl;

    return 0;
}

// Problem No 13
// Problem Name: