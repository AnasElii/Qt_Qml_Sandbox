#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    // // List of 3x3
    int matrix[3][3];

    // 1th Row
    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[0][2] = 2;

    // 2th Row
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 2;

    // 2th Row
    matrix[2][0] = 0;
    matrix[2][1] = 1;
    matrix[2][2] = 2;

    // cout << "----------------------------" << endl;
    // cout << "|                          |" << endl;
    // cout << "----------------------------" << endl;

    // for (int col = 0; col < 3; col++)
    // {
    //     cout << "| ";
    //     for (int row = 0; row < 3; row++)
    //     {
    //         cout << matrix[col][row] << "| ";
    //     }
    //     cout << endl;
    // }
    // cout << "----------------------------" << endl;

    vector<vector<int>> vectoreMatrix;
    vectoreMatrix.resize(3, vector<int>(3, 0));
    for (int row = 0; row < 3; row++)
    {
        auto &rowMat = vectoreMatrix[row];
        for (int col = 0; col < 3; col++)
        {
            rowMat[col] = matrix[row][col];
        }
    }

    cout << "----------------------------" << endl;

    // for (int row = 0; row < 3; row++)
    // {
    //     cout << "| ";
    //     for (int col = 0; col < 3; col++)
    //     {
    //         cout << vectoreMatrix[row][col] << "| ";
    //     }
    //     cout << endl;
    // }
    {
        std::cout << "Medal";
        std::cout << '\t';
        for (int column = 0; column < vectoreMatrix[0].size(); ++column)
        {
            std::cout << "C" << column + 1 << '\t';
        }

        std::cout << "\n----------------------------\n";

        for (int row = 0; row < vectoreMatrix.size(); ++row)
        {
            std::cout << "Row" << row + 1 << ' ';
            auto &rowMatrix = vectoreMatrix[row];
            std::cout << '\t';
            for (int column = 0; column < vectoreMatrix[0].size(); ++column)
            {
                std::cout << rowMatrix[column] << '\t';
            }
            std::cout << '\n';
        }
    }
    //   std::ostream_iterator<int>(std::cout, " "))));
    // std::copy(vectoreMatrix[0].begin(), vectoreMatrix[0].end(), std::ostream_iterator<int>(std::cout, " "));

    cout << "----------------------------" << endl;

    cout << "Hello World!" << endl;
    return 0;
}