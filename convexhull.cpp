#include <bits/stdc++.h>
using namespace std;

int n;
struct point {
    long double x, y;
};
bool cmp(point a, point b) {
    return ((a.y < b.y) || (a.y == b.y && a.x < b.x));
}
bool clock_wise(point a, point b, point c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) < 0;
}
bool counter_clock_wise(point a, point b, point c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) > 0;
}
vector<point> poly;
void convex_hull(vector<point> &pt) {
    sort(pt.begin(), pt.end(), &cmp);
    point left_most = pt[0], right_most = pt[n - 1];
    vector<point> upper, lower;
    upper.push_back(left_most); lower.push_back(left_most);
    for (int i = 1; i < n; ++i) {
        if (i == n - 1 || clock_wise(left_most, pt[i], right_most)) {
            while (upper.size() >= 2 && !clock_wise(upper[upper.size() - 2], upper[upper.size() - 1], pt[i])) {
                upper.pop_back();
            }
            upper.push_back(pt[i]);
        }
        if (i == n - 1 || counter_clock_wise(left_most, pt[i], right_most)) {
            while (lower.size() >= 2 && !counter_clock_wise(lower[lower.size() - 2], lower[lower.size() - 1], pt[i])) {
                lower.pop_back();
            }
            lower.push_back(pt[i]);
        }
    }
    for (int i = 0; i < (int)lower.size(); ++i) {
        poly.push_back(lower[i]);
    }
    for (int i = upper.size() - 2; i > 0; --i) {
        poly.push_back(upper[i]);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector<point> pt(n);
    for (int i = 0; i < n; ++i) {
        cin >> pt[i].x >> pt[i].y;
    }
    convex_hull(pt);
    for (const auto &p : poly) {
        cout << p.x << " " << p.y << "\n";
    }
    return 0;
}