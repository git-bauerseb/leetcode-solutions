#include <bits/stdc++.h>

using namespace std;

#define _WIDTH .first
#define _HEIGHT .second

/*
class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {            
            int rows = matrix.size();
            int cols = matrix[0].size();

            if (rows == 1 && cols == 1) {return matrix[0][0] == '1' ? 1 : 0;}

            vector<vector<pair<int, int>>> largest(rows, vector<pair<int,int>>(cols));

            if (matrix[0][0] == '1') {
                largest[0][0]_WIDTH = 1;
                largest[0][0]_HEIGHT = 1;
            }

            for (int y = 1; y < rows; y++) {
                if (matrix[y][0] == '1') {
                    largest[y][0]_HEIGHT = largest[y-1][0]_HEIGHT + 1;
                    largest[y][0]_WIDTH = 1;
                }
            }

            for (int x = 1; x < cols; x++) {
                if (matrix[0][x] == '1') {
                    largest[0][x]_WIDTH = largest[0][x-1]_WIDTH + 1;
                    largest[0][x]_HEIGHT = 1;
                }
            }

            int largestArea = numeric_limits<int>::min();



            for (int y = 1; y < rows; y++) {

                vector<pair<int,int>> swap_row(cols);
                for (int x = 1; x < cols; x++) {
                    int c_max_width = 0;
                    int c_max_height = 0;

                    int c_width = 0;
                    int c_height = 0;

                    if (matrix[y][x] == '1') {
                        
                        c_max_width = c_max_height = 1;

                        // Case 1
                        if (matrix[y][x-1] == '1' && matrix[y-1][x] == '1' && matrix[y-1][x-1] == '1') {

                            c_width = min(largest[y][x-1]_WIDTH, largest[y-1][x-1]_WIDTH);
                            c_height = min(largest[y-1][x-1]_HEIGHT, largest[y-1][x]_HEIGHT);

                            c_max_width = max(c_max_width, c_width);
                            c_max_height = max(c_max_height, c_height);
                        }
                        
                        // Case 2 & 3
                        if (matrix[y-1][x] == '1' || matrix[y][x-1] == '1') {
                            // Case 2
                            c_width = min(largest[y][x-1]_WIDTH, largest[y-1][x]_WIDTH);
                            c_max_height = max(c_max_height, largest[y-1][x]_HEIGHT + 1);
                            c_max_width = max(c_max_width, c_width);
                        
                        
                            c_height = min(largest[y][x-1]_HEIGHT, largest[y-1][x]_HEIGHT);
                            c_max_height = max(c_max_height, c_height);
                            c_max_width = (c_max_width, largest[y][x-1]_WIDTH + 1);

                            
                        }

                        swap_row[x]_WIDTH = c_max_width;
                        swap_row[x]_HEIGHT = c_max_height;
                        largestArea = max(largestArea, c_max_width * c_max_height);
                    } else {
                        swap_row[x]_WIDTH = 0;
                        swap_row[x]_HEIGHT = 0;
                    }

                    for (int y = 0; y < rows; y++) {
                        for (int x = 0; x < cols; x++) {
                            cout << largest[y][x]_WIDTH * largest[y][x]_HEIGHT << " ";
                        }
                        cout << "\n";
                    }
                }

                largest[y] = swap_row;                
            }

            return largestArea;
        }
};
*/


class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {

            int rows = matrix.size();
            int cols = matrix[0].size();


            vector<vector<int>> colsAcc(rows, vector<int>(cols));
            vector<vector<int>> rowsAcc(rows, vector<int>(cols));

            for (int x = 0; x < cols; x++) {
                colsAcc[0][x] = matrix[0][x] - '0'; 
            }

            for (int y = 0; y < rows; y++) {
                rowsAcc[y][0] = matrix[y][0] - '0';
            }

            for (int y = 1; y < rows; y++) {
                for (int x = 0; x < cols; x++) {
                    if (matrix[y][x] - '0' == 1) {
                        colsAcc[y][x] = colsAcc[y-1][x] + 1;
                    }
                }
            }

            for (int y = 0; y < rows; y++) {
                for (int x = 1; x < cols; x++) {
                    if (matrix[y][x] - '0' == 1) {
                        rowsAcc[y][x] = rowsAcc[y][x-1] + 1;
                    }
                }
            }

            int largest = numeric_limits<int>::min();

            for (int y = 0; y < rows; y++) {
                for (int x = 0; x < cols; x++) {

                    int width = rowsAcc[y][x];

                    for (int i = 0; i < colsAcc[y][x] && width * colsAcc[y][x] ; i++) {
                        width = min(width, rowsAcc[y - i][x]);
                    }

                    int height = colsAcc[y][x];
                    for (int i = 0; i < width; i++) {
                        height = min(height, colsAcc[y][x  - i]);
                    }

                    largest = max(largest, width * height);
                }
            }

            return largest;
        }
};

int main() {

    vector<vector<char>> rect;
    rect.push_back({'0', '0', '1'});
    rect.push_back({'1', '1', '1'});

    Solution solution{};
    int maxArea = solution.maximalRectangle(rect);

    cout << maxArea << "\n";

    return 0;
}