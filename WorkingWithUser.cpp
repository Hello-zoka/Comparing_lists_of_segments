#include <iostream>
#include <vector>
#include "header.h"

using namespace std;


vector<segment> ReadListOfSegments() {
    int num_of_segments;
    vector<segment> list_of_nodes;
    cin >> num_of_segments;
    for (size_t i = 0; i < num_of_segments; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        list_of_nodes.push_back({{x1, y1},
                                 {x2, y2}});
    }
    return list_of_nodes;
}

void PrintOutput(vector<segment> &list_of_segments) {
    cout << "Number of segemts: " << list_of_segments.size() << '\n';
    for (segment cur_segment : list_of_segments) {
        cout << "x1: " << cur_segment.first_point.x << " y1: " << cur_segment.first_point.y << " x2: "
             << cur_segment.second_point.x << " y2: " << cur_segment.second_point.y << '\n';
    }
}