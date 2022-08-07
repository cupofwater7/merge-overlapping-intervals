#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals);

int main()
{
    vector<vector<int>> result = mergeOverlappingIntervals({ {1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10} });

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout  << result[i][j] << " ";
        }
        cout << "],";
    }
    return 0;
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    // Write your code here.

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> output;
    int output_index = 0;

    output = { {intervals[0][0], intervals[0][1]} };

    for (int i = 1; i < intervals.size(); i++)
    {
        if (output[output_index][1] >= intervals[i][0])
        {
            output[output_index] = { output[output_index][0], max(output[output_index][1], intervals[i][1]) };
        }
        else
        {
            output_index++;
            output.push_back({ intervals[i][0], intervals[i][1] });
        }
    }

    return output;
}
