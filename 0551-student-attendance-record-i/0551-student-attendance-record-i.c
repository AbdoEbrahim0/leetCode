bool checkRecord(char* s) {
    int absentCount = 0;
    int lateStreak = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absentCount++;
            if (absentCount >= 2) {
                return false;
            }
            lateStreak = 0; // Reset late streak on 'A'
        } 
        else if (s[i] == 'L') {
            lateStreak++;
            if (lateStreak >= 3) {
                return false;
            }
        } 
        else { // 'P'
            lateStreak = 0; // Reset late streak on 'P'
        }
    }
    
    return true;
}