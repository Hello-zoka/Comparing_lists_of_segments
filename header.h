//
// Created by Yurij Zaytsev on 12.01.2021.
//

#include <vector>
#include <iostream>

struct point {
    int x, y;

    bool operator==(const point &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    void Print() {
        std::cout << x << " " << y << " ";
    }
};

struct segment {
    point first_point, second_point;

    bool operator==(const segment &rhs) const {
        return first_point == rhs.first_point &&
               second_point == rhs.second_point;
    }

    void Print() {
        std::cout << "Segment:\n";
        std::cout << "First end of segment: ";
        first_point.Print();
        std::cout << "Second end of segment: ";
        second_point.Print();
        std::cout << "\n";
    }
};

std::vector<segment> ReadListOfSegments();

void PrintOutput(std::vector<segment> &);

bool Compare(std::vector<segment> &, std::vector<segment> &);

void Normalize(std::vector<segment> &);

bool NormalizeTesting();

segment Merge(segment, segment);

