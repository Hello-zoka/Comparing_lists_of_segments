#include <iostream>
#include <vector>
#include <algorithm>
#include "hedaer.h"

using namespace std;

bool Compare(vector<segment> &list1, vector<segment> &list2) {
    if (list1.size() != list2.size()) return false;
    for (int ind = 0; ind < list1.size(); ind++) {
        if (list1[ind].first_point.x > list1[ind].second_point.x)
            swap(list1[ind].first_point, list1[ind].second_point);
        if (list2[ind].first_point.x > list2[ind].second_point.x)
            swap(list2[ind].first_point, list2[ind].second_point);
        // making x-coordinate of first end of segment less or equal than x-cordinate of second end og segment
    }
    for (int ind = 0; ind < list1.size(); ind++) {
        if (find(list2.begin(), list2.end(), list1[ind]) == list2.end()) {
            // trying to find ind-element of first list ing second list
            return false;
        }
    }
    return true; // equal sizes and all elements of first list contain in second one
}