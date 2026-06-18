class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = 30 * hour + 0.5*minutes;
        double minAngle = 6 * minutes;

        double angle = abs(hourAngle - minAngle);

        return min(angle, 360-angle);
    }
};