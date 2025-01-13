
#include <iostream>
using namespace std;

class TVRemote {
private:
    bool isOn = false;
    int volume = 0;
    int currentChannel = 1;
    const int MAX_VOLUME = 30;
    const int MAX_CHANNEL = 100;

public:

    // Inline function for turning TV on
    inline void turnOn() {
        if (!isOn) {
            cout << "TV turned ON." << endl;
            isOn = true;
        } else {
            cout << "TV is already ON." << endl;
        }
    }

    // Inline function for turning TV off
    inline void turnOff() {
        if (isOn) {
            cout << "TV turned OFF." << endl;
            isOn = false;
        } else {
            cout << "TV is already OFF." << endl;
        }
    }

    // Inline function for increasing volume
    inline void volumeUp() {
        if (isOn) {
            if (volume < MAX_VOLUME) {
                volume++;
                cout << "Volume: " << volume << endl;
            } else {
                cout << "Volume is already at the maximum." << endl;
            }
        } else {
            cout << "TV is OFF. Please turn it ON." << endl;
        }
    }

    // Inline function for decreasing volume
    inline void volumeDown() {
        if (isOn) {
            if (volume > 0) {
                volume--;
                cout << "Volume: " << volume << endl;
            } else {
                cout << "Volume is already at the minimum." << endl;
            }
        } else {
            cout << "TV is OFF. Please turn it ON." << endl;
        }
    }

    // Inline function for increasing channel
    inline void channelUp() {
        if (isOn) {
            if (currentChannel < MAX_CHANNEL) {
                currentChannel++;
                cout << "Channel: " << currentChannel << endl;
            } else {
                cout << "Channel is already at the maximum." << endl;
            }
        } else {
            cout << "TV is OFF. Please turn it ON." << endl;
        }
    }

    // Inline function for decreasing channel
    inline void channelDown() {
        if (isOn) {
            if (currentChannel > 1) {
                currentChannel--;
                cout << "Channel: " << currentChannel << endl;
            } else {
                cout << "Channel is already at the minimum." << endl;
            }
        } else {
            cout << "TV is OFF. Please turn it ON." << endl;
        }
    };
};

int main() {
    TVRemote remote;

    remote.turnOn();
    remote.volumeUp();
    remote.volumeUp();
    remote.channelUp();
    remote.channelDown();
    remote.turnOff();
    remote.volumeUp(); // Check behavior when TV is off

    return 0;
}
