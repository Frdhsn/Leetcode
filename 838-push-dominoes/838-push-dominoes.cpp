
    class Solution {
    public:
        string pushDominoes(string s) {
            int n = s.size();
            vector<int> right(n), left(n);
            int r = -1, l = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'R')r = i;
                else if (s[i] == 'L')r = -1;
                right[i] = r;
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'L')l = i;
                else if (s[i] == 'R')l = -1;
                left[i] = l;
            }

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '.')
                {
                    if (right[i] == -1 && left[i] == -1)
                        continue;
                    if (right[i] == -1 && left[i] != -1)s[i] = 'L';
                    else if (left[i] == -1 && right[i] != -1)s[i] = 'R';
                    else
                    {
                        if (left[i] - i < i - right[i]) s[i] = 'L';
                        else if (i - right[i] < left[i] - i)s[i] = 'R';

                    }

                }
            }
            return s;

        }
    };