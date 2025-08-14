#include <bits/stdc++.h>

using Point = std::pair<double, double>;

class Triangle {
private:
    Point a, b, c;
    double area;

    // Calculate distance between two points
    static double calculateDistance(const Point& p1, const Point& p2) {
        double dx = p1.first - p2.first;
        double dy = p1.second - p2.second;
        return std::sqrt(dx * dx + dy * dy);
    }

    // Calculate triangle area using Heron's formula
    void calculateArea() {
        double sideA = calculateDistance(a, b);
        double sideB = calculateDistance(b, c);
        double sideC = calculateDistance(c, a);
        
        double semiPerimeter = (sideA + sideB + sideC) / 2.0;
        area = std::sqrt(semiPerimeter * 
                        (semiPerimeter - sideA) * 
                        (semiPerimeter - sideB) * 
                        (semiPerimeter - sideC));
    }

public:
    Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {
        calculateArea();
    }

    double getArea() const { return area; }
    Point getPointA() const { return a; }
    Point getPointB() const { return b; }
    Point getPointC() const { return c; }

    // Check if a point lies inside this triangle
    bool containsPoint(const Point& p) const {
        const double EPSILON = 1e-5;
        
        // Create three triangles using the test point and two vertices of original triangle
        Triangle t1(a, b, p);
        Triangle t2(b, c, p);
        Triangle t3(c, a, p);
        
        // Sum of areas of three triangles should equal original triangle's area
        double areaSum = t1.getArea() + t2.getArea() + t3.getArea();
        return std::abs(areaSum - area) < EPSILON;
    }

    // Check if another triangle's vertices are all contained within this triangle
    bool containsTriangle(const Triangle& other) const {
        return containsPoint(other.getPointA()) && 
               containsPoint(other.getPointB()) && 
               containsPoint(other.getPointC());
    }
};

// Find the longest sequence of triangles where each triangle contains the previous one
int findLongestTriangleSequence(std::vector<Triangle>& triangles) {
    // Sort triangles by area in ascending order
    std::sort(triangles.begin(), triangles.end(), 
              [](const Triangle& a, const Triangle& b) {
                  return a.getArea() < b.getArea();
              });

    std::vector<int> longestSequence(triangles.size(), 1);
    int maxLength = 1;

    // Dynamic programming approach to find longest sequence
    for (size_t i = 0; i < triangles.size(); i++) {
        for (size_t j = 0; j < i; j++) {
            if (triangles[i].containsTriangle(triangles[j])) {
                longestSequence[i] = std::max(longestSequence[i], 
                                            longestSequence[j] + 1);
            }
        }
        maxLength = std::max(maxLength, longestSequence[i]);
    }

    return maxLength;
}

int main() {
    std::ifstream input("dtamgiac.inp");
    std::ofstream output("dtamgiac.out");

    int n;
    input >> n;

    std::vector<Triangle> triangles;
    triangles.reserve(n);

    // Read triangle coordinates
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2, x3, y3;
        input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        triangles.emplace_back(
            Point(x1, y1),
            Point(x2, y2),
            Point(x3, y3)
        );
    }

    int result = findLongestTriangleSequence(triangles);
    output << result << std::endl;

    return 0;
}