class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12)
            hour = 0;
        
        double hourPerc = (double) hour / 12, minPerc = (double) minutes / 60;
        double hourShift = minPerc * 30;
        
        double hourAngle = (double) hourPerc * 360, minuteAngle = (double) minPerc * 360;
        hourAngle += hourShift;
        
        double diff = abs(minuteAngle - hourAngle);
        
        return min(diff, 360 - diff);
    }
};