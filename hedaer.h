//
// Created by Yurij Zaytsev on 12.01.2021.
//

#ifndef CODSTYLE_HEDAER_H

#include <vector>
#include <iostream>

struct point {
    int x, y;

    bool operator==(const point &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    void Print() {
        std::cerr << x << " " << y << " ";
    }
};

struct segment {
    point first_point, second_point;

    bool operator==(const segment &rhs) const {
        return first_point == rhs.first_point &&
               second_point == rhs.second_point;
    }

    void Print() {
        first_point.Print();
        second_point.Print();
        std::cerr << "\n";
    }
};

std::vector<segment> ReadListOfSegments();

void PrintOutput(std::vector<segment> &);

bool Compare(std::vector<segment> &, std::vector<segment> &);

void Normalize(std::vector<segment> &);

bool NormalizeTesting();

segment Merge(segment, segment);

#define CODSTYLE_HEDAER_H

#endif //CODSTYLE_HEDAER_H
