#include <iostream>

using namespace std;

class Numbers {
    public:
        string numberConverter(int num) { //to return out numerals as writing
            string strNum[31] {
                "o' clock", //0 is used as o' clock
                "one", "two", "three", "four", "five",
                "six", "seven", "eight", "nine", "ten",
                "eleven", "twelve", "thirteen", "fourteen", "quarter", //15 is used as quarter
                "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
                "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
                "twenty six", "twenty seven", "twenty eight", "twenty nine", "half" //30 is used as half
            };
            string result = strNum[num];
            return result;
        }
};

int main() {
    Numbers write; // created the object for converting numbers into letters
    int hour{0}, minute{0};

    cin >> hour >> minute;

    //checking if numbers are inside the range
    if(hour < 1 || hour > 23) {
        return 0;
    }

    //we dont have to check for minute since we split the outcome for which range it is. If number is outside the range, it will go into last else and exit.
    //o' clock
    if(minute == 0) {
        if(hour > 12) {
            hour %=12;
        }
        cout << write.numberConverter(hour) << " " << write.numberConverter(minute); // number 0 returns "o' clock" from the function
    }
    //past
    else if(minute >= 1 && minute <= 30) {
        if(hour > 12) { // makes hour between 1 to 12
            hour %=12;
        }
        if(minute == 15 || minute == 30) { //if number is 15 or 30, we dont want to write "minutes"
            cout << write.numberConverter(minute) << " past " << write.numberConverter(hour);
            return 0;
        }
        cout << write.numberConverter(minute) << " minutes past " << write.numberConverter(hour);
    }
    //to
    else if(minute > 30 && minute < 60) {
        if(hour > 12) {
            hour %=12;
        }
        hour++; //while writing "to" between hour and minute, we need hour to be next hour
        minute = 60 - minute; //to know how many minutes left until next hour
        if(minute == 15) { //quarter
            cout << write.numberConverter(minute) << " to " << write.numberConverter(hour);
            return 0;
        }
        cout << write.numberConverter(minute) << " minutes to " << write.numberConverter(hour);
    }
    //default. If minute is not in range, it will get to this one and exit program
    else {
        return 0;
    }

    return 0;
}
