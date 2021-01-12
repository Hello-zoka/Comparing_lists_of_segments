#include <iostream>
#include <vector>
#include "hedaer.h"

using namespace  std;

int main() {
    vector<segment> list_of_segments = ReadInput();
    //Merge(lsit_of_nodes);
    PrintOutput(list_of_segments);
    return 0;
}
