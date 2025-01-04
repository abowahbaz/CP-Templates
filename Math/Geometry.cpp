#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

namespace geometry
{
    // ! Angles are in radians
    const double EPS = 1E-12, PI = acos(-1.0);
    typedef complex<double> point;
    // * points ,lines and vectors are represented by complex numbers
#define X real()
#define Y imag()

    int dblcmp(double a, double b) {
        return fabs(a - b) < EPS ? 0 : a < b ? -1 : 1;
        // 0 if a == b, -1 if a < b, 1 if a > b
    }

    // * Points & Vectors

    double dist(point a, point b) { // euclidean distance
        return hypot(a.X - b.X, a.Y - b.Y);
    }

    double dot(point a, point b) {
        return real(conj(a) * b);
    }

    double cross(point a, point b) {
        return imag(conj(a) * b);
    }

    double length(point a)
    {
        return hypot(a.X, a.Y);
    }
    bool is_collinear(point a, point b, point c) {
        return dblcmp(cross(b - a, c - a), 0) == 0;
    }
    bool is_on_ray(point a, point b, point c) { // check if c on ray ab
        return dblcmp(dot(b - a, c - a), 0) == 1;
    }
    bool is_on_segment(point a, point b, point c) { // check if c on segment ab
        return dblcmp(abs(a - c) + abs(b - c), abs(a - b)) == 0;
    }
    bool vector_intersect(point vec1, point vec2)
    {
        return !dblcmp(cross(vec1, vec2), 0);
    }
    // * Lines 	
    bool line_parallel(point a, point b, point c, point d) // ab || cd
    {
        return dblcmp(cross(b - a, d - c), 0) == 0;
    }

    bool line_intersect(point a, point b, point c, point d) // ab ∩ cd
    {
        if (line_parallel(a, b, c, d)) return false;
        double a1 = cross(d - c, a - c);
        double a2 = cross(d - c, b - c);
        if ((a1 > 0 && a2 > 0) || (a1 < 0 && a2 < 0)) return false;
        a1 = cross(b - a, c - a);
        a2 = cross(b - a, d - a);
        if ((a1 > 0 && a2 > 0) || (a1 < 0 && a2 < 0)) return false;
        return true;
    }

    bool line_perpendicular(point a, point b, point c, point d) // if ab ⊥ cd
    {
        return dblcmp(dot(b - a, d - c), 0) == 0;
    }

    bool line_coincide(point a, point b, point c, point d) {
        return line_parallel(a, b, c, d) && line_parallel(a, c, a, d);
    }

    point get_intersection(point a, point b, point c, point d) {
        if (line_parallel(a, b, c, d)) return point(nan(""), nan(""));
        double a1 = cross(d - c, a - c);
        double a2 = cross(d - c, b - c);
        return (a1 * b - a2 * a) / (a1 - a2);
    }

    point rotate_by(point a, double theta) {
        return a * polar(1.0, theta);
    }

    point rotate_around(point a, point b, double theta) {
        return (a - b) * polar(1.0, theta) + b;
    }
    point translate(point a, point b) {
        return a + b;
    }
    int ccw(point p0, point p1, point p2)
    {
        point v1(p1 - p0), v2(p2 - p0);
        if (dblcmp(cross(v1, v2), 0) > 0) return +1; // counter clockwise
        if (dblcmp(cross(v1, v2), 0) < 0) return -1; // clockwise

        if (dblcmp(v1.X * v2.X, 0) < 0 || dblcmp(v1.Y * v2.Y, 0) < 0) // p2 is behind p1
            return -1;

        if (dblcmp(norm(v1), norm(v2)) < 0) return +1; // p2 is in front of p1

        return 0; // undefined case (collinear)
    }

    double dist_to_line(point p, point a, point b, point &c)
    {
        point ap = p - a, ab = b - a;
        double u = dot(ap, ab) / norm(ab);
        c = translate(a, ab * u);
        return dist(p, c);
    }

    double dist_to_segment(point p, point a, point b, point &c) // 4th parameter is the closest point
    {
        point ap = p - a, ab = b - a;
        double u = dot(ap, ab) / norm(ab);
        if (u < EPS)
        {
            c = a;
            return dist(p, a);
        }
        if (u > 1 - EPS)
        {
            c = b;
            return dist(p, b);
        }
        return dist_to_line(p, a, b, c);
    }

    // * Angles
    double to_rad(double theta) {
        return theta * PI / 180.0;
    }

    double to_deg(double theta) {
        return theta * 180.0 / PI;
    }

    double fix_angle(double theta) {
        int sign = (theta < 0 ? -1 : theta > 2.0 * PI ? 1 : 0);
        return theta + (sign * 2.0 * PI);
    }

    double angle(point a) {
        return atan2(imag(a), real(a));
    }

    double angle(point a, point b) {
        return fix_angle(angle(b) - angle(a));
    }

    // * Circles
    bool is_inside_circle(point center, double radius, point p) {
        return dblcmp(radius, abs(p - center)) == 1;
    }

    bool is_on_circle(point center, double radius, point p) {
        return dblcmp(radius, abs(p - center)) == 0;
    }
};


void Solve()
{

}

signed main()
{
#if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        Solve();
        cout << "\n";
    }
    return 0;
}
