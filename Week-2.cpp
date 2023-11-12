#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

void refreshTime(time_t &currentTime, tm &timeinfo, int &total) {
    time(&currentTime);
    localtime_s(&timeinfo, &currentTime);
    int hour = timeinfo.tm_hour;
    int min = timeinfo.tm_min;
    total = (hour * 60) + min;
}

int main() {

    // Get the current time
    time_t currentTime;
    tm timeinfo;
    int total;
    refreshTime(currentTime, timeinfo, total);
    int initialMins = total;
    int displayMins = 0;
    int displayHour = 10;

    do {
        char input = _getch();

        if (input == 'r') {
            refreshTime(currentTime, timeinfo, total);
            displayMins = total - initialMins;
            cout << 10 << ":" << 0 << displayMins << endl;
        }
    } while (true);

	return 0;
}