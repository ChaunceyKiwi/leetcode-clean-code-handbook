class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();

        int n;
        if (m > 0) {
            n = matrix[0].size();
        } else {
            n = 0;
        }

        int border = 0;

        while ((m > 2 * border) && (n > 2 * border)) {
            for (int x = border; x < n - border; x++) {
                res.push_back(matrix[border][x]);
            }

            for (int y = 1 + border; y < m - border; y++) {
                res.push_back(matrix[y][n-1-border]);
            }

            if (m > 2 * border + 1) {
                for (int x = n - 2 - border; x >= border; x--) {
                    res.push_back(matrix[m-1-border][x]);
                }
            }

            if (n > 2 * border + 1) {
                for (int y = m - 2 - border; y >= 1 + border; y--) {
                    res.push_back(matrix[y][border]);
                }
            }

            border++;
        }

        return res;
    }
};
