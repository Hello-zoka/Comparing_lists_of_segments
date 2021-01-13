#include <iostream>
#include <vector>
#include "hedaer.h"

using namespace std;

bool IsPointsOnLine(point &a, point &b, point &c) {
    return (c.x * (b.y - a.y) - c.y * (b.x - a.x) == a.x * b.y - b.x * a.y); // checking if points are on one line
}

bool IsSegmentsOnLine(segment &a, segment &b) {
    return IsPointsOnLine(a.first_point, b.first_point, b.second_point) &&
           IsPointsOnLine(a.second_point, b.first_point, b.second_point);
    // checking both ends of first segment of lying on one line with second segment
}

bool NeedMerging(segment &a, segment &b) {
    if (a.first_point.x > a.second_point.x) swap(a.first_point, a.second_point);
    if (b.first_point.x > b.second_point.x) swap(b.first_point, b.second_point);
    return IsSegmentsOnLine(a, b) && ((a.first_point.x <= b.first_point.x && b.first_point.x <= a.second_point.x) ||
                                      (a.first_point.x <= b.second_point.x && b.second_point.x <= a.second_point.x) ||
                                      (b.first_point.x <= a.first_point.x && a.first_point.x <= b.second_point.x) ||
                                      (b.first_point.x <= a.second_point.x && a.second_point.x <= b.second_point.x));
    // If two segmets are on one line, checking if one of ends of the second segment are between ends of first segment(comparing x-coordinate if enough)
    // 4 cases - checking if one of 4 ends is lying between two ends of another segment
}

segment Merging(segment &a, segment &b) {
    segment result;
    vector<point> ends_of_segments = {a.first_point, a.second_point, b.first_point, b.second_point};
    sort(ends_of_segments.begin(), ends_of_segments.end(), [&](const point &first_point, const point &second_point) {
        return (first_point.x <= second_point.x);
    }); // sorting points by x-coordinate
    result.first_point = ends_of_segments[0];
    result.second_point = ends_of_segments.back();
    // merge of two crossing segmets - segment with "left" and "right" by x-coordinate ends
    return result;
}

bool Relaxing(vector<segment> &current_list_of_segments) {
    bool was_changed = false; // shows if relaxing is necessary
    vector<segment> result;
    for (int first_id = 0; first_id < current_list_of_segments.size(); first_id++) {
        bool was_merged = false;
        for (int second_id = 0; second_id < result.size(); second_id++) {
            // iterate over the idexes of two segments
            if (NeedMerging(current_list_of_segments[first_id],
                            result[second_id])) { // checking if we need to merge two segments
                result[second_id] = Merging(current_list_of_segments[first_id],
                                            result[second_id]);  // merging these to segments
                was_changed = true;
                was_merged = true;
                break;
            }
        }
        if (was_merged) continue;
        result.push_back(current_list_of_segments[first_id]);
    }
    swap(current_list_of_segments, result); // relaxing original list
    return was_changed;
}

void Normalize(vector<segment> &list_of_segmets) {
    while (Relaxing(list_of_segmets));
    // trying to merge some segments as long as possible
    // "greedy" solve of course can be used
}

bool NormalizeTesting() {
    vector<pair<vector<segment>, vector<segment>>> tests;
    vector<segment> inp = {{0,  0,  1,  1},
                           {0,  0,  2,  2},
                           {2,  2,  6,  6},
                           {2,  2,  10, 17},
                           {15, 20, 30, -120},
                           {5,  5,  -4, -4}};
    vector<segment> answer = {{-4, -4, 6,  6},
                              {2,  2,  10, 17},
                              {15, 20, 30, -120}};
    // test with a lot of cases :)
    vector<int> indexes;
    for (int i = 0; i < inp.size(); i++) {
        indexes.push_back(i);
    }
    while (next_permutation(indexes.begin(), indexes.end())) { // checking if it works with all permutations
        vector<segment> cur_inp;
        for (int pos : indexes)
            cur_inp.push_back(inp[pos]);
        tests.push_back({cur_inp, answer});
    }
    for (int test_id = 0; test_id < tests.size(); test_id++) {
        Normalize(tests[test_id].first);
        for (segment cur_segement : tests[test_id].first) {
            if (find(tests[test_id].second.begin(), tests[test_id].second.end(), cur_segement) ==
                tests[test_id].second.end())
                return false; // checking if current segment in result
        }
    }
    return true; // Everything is okay
}