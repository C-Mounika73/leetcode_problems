/*
LeetCode 1344 - Angle Between Hands of a Clock

Problem:
Given the hour and minutes on an analog clock, return the smaller angle
formed between the hour hand and the minute hand.

Approach:
Compute the minute hand angle as minutes × 6 degrees. Compute the hour
hand angle as (hour % 12) × 30 degrees plus 0.5 degrees for each minute.
Find the absolute difference between the two angles and return the smaller
of that difference and its complement with respect to 360 degrees.

Pattern: Math

Time Complexity: O(1)
Space Complexity: O(1)
*/

double angleClock(int hour, int minutes) {
    double minAngle=minutes*6.0;
    double hourAngle = (hour % 12)*30.0 + minutes*0.5;
    double angle=fabs(hourAngle-minAngle);

    return fmin(angle,360.0-angle);
}