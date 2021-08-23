#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

int main() {
    freopen("", "r", stdin); // !!! INSERT path to input file
    vector<segment> list_of_segments = ReadListOfSegments(); // Reading 1st list of segments
    vector<segment> list_of_segments2 = ReadListOfSegments(); // Reading 2nd list of segments
//    if (!NormalizeTesting()) {
//        cerr << "\n!\n!\nERROR\n!\n!\n";      Checking if everything is okay
//    }

    Normalize(list_of_segments); // Merging of crossing segments
    Normalize(list_of_segments2);
    // PrintOutput(list_of_segments); // Printing list of segments for debugging

    if (Compare(list_of_segments, list_of_segments2)) {
        cout << "Yes, it is similar!\n";
    } else {
        cout << "No, it is not similar :(\n";
    }
    return 0;
}
