#include <iostream>
using namespace std;

// TV class representing the TV with basic functionalities
class TV {
private:
    bool isOn;
    int volume;
    int channel;

public:
    TV() : isOn(false), volume(10), channel(1) {}

    // Inline method to turn the TV ON
    inline void turnOn() {
        isOn = true;
        cout << "TV is turned ON." << endl;
    }

    // Inline method to turn the TV OFF
    inline void turnOff() {
        isOn = false;
        cout << "TV is turned OFF." << endl;
    }

    // Inline method to increase volume
    inline void volumeUp() {
        if (isOn) {
            volume++;
            cout << "Volume increased to: " << volume << endl;
        } else {
            cout << "TV is OFF. Cannot increase volume." << endl;
        }
    }

    // Inline method to decrease volume
    inline void volumeDown() {
        if (isOn) {
            if (volume > 0) {
                volume--;
                cout << "Volume decreased to: " << volume << endl;
            } else {
                cout << "Volume is at minimum." << endl;
            }
        } else {
            cout << "TV is OFF. Cannot decrease volume." << endl;
        }
    }

    // Inline method to change channel
    inline void changeChannel(int newChannel) {
        if (isOn) {
            channel = newChannel;
            cout << "Channel changed to: " << channel << endl;
        } else {
            cout << "TV is OFF. Cannot change channel." << endl;
        }
    }
};

// TVRemote class representing the remote control
class TVRemote {
private:
    TV& tv; // Reference to TV object

public:
    TVRemote(TV& television) : tv(television) {}

    void on() {
        tv.turnOn();
    }

    void off() {
        tv.turnOff();
    }

    void volumeUp() {
        tv.volumeUp();
    }

    void volumeDown() {
        tv.volumeDown();
    }

    void changeChannel(int newChannel) {
        tv.changeChannel(newChannel);
    }
};

// Main function to demonstrate the functionality
int main() {
    TV myTV;
    TVRemote remote(myTV);

    remote.on();
    remote.volumeUp();
    remote.changeChannel(5);
    remote.volumeDown();
    remote.off();

    return 0;
}
