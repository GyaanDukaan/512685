#include <iostream>
#include <functional>
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
        }
        else {
            cout << "TV is OFF. Cannot increase volume." << endl;
        }
    }

    // Inline method to decrease volume
    inline void volumeDown() {
        if (isOn) {
            if (volume > 0) {
                volume--;
                cout << "Volume decreased to: " << volume << endl;
            }
            else {
                cout << "Volume is at minimum." << endl;
            }
        }
        else {
            cout << "TV is OFF. Cannot decrease volume." << endl;
        }
    }

    // Inline method to change channel
    inline void changeChannel(int newChannel) {
        if (isOn) {
            channel = newChannel;
            cout << "Channel changed to: " << channel << endl;
        }
        else {
            cout << "TV is OFF. Cannot change channel." << endl;
        }
    }
};

// Functor for a TV remote
class TVRemoteFunctor {
public:
    TV& tv;

    TVRemoteFunctor(TV& television) : tv(television) {}

    void on() { tv.turnOn(); }
    void off() { tv.turnOff(); }
    void volumeUp() { tv.volumeUp(); }
    void volumeDown() { tv.volumeDown(); }
    void changeChannel(int newChannel) { tv.changeChannel(newChannel); }
};

class TVRemote {
private:
    TV& tv; // Reference to TV object

public:
    TVRemote(TV& television) : tv(television) {}

    // Using function pointers for callbacks
    void execute(void (TV::* action)()) {
        (tv.*action)();
    }

    // Using function pointer for channels with different overloads
    void execute(void (TV::* action)(int), int channel) {
        (tv.*action)(channel);
    }
};

int main() {
    TV myTV;

    // Using functor
    TVRemoteFunctor functorRemote(myTV);
    functorRemote.on();
    functorRemote.volumeUp();
    functorRemote.changeChannel(5);
    functorRemote.volumeDown();
    functorRemote.off();

    // Using function pointers
    TVRemote pointerRemote(myTV);
    pointerRemote.execute(&TV::turnOn);
    pointerRemote.execute(&TV::volumeUp);
    pointerRemote.execute(&TV::changeChannel, 7);
    pointerRemote.execute(&TV::volumeDown);
    pointerRemote.execute(&TV::turnOff);

    // Using a lambda function for callback
    auto volumeLambda = [&myTV]() { myTV.volumeUp(); };
    volumeLambda();

    auto changeChannelLambda = [&myTV](int newChannel) { myTV.changeChannel(newChannel); };
    changeChannelLambda(10);

    return 0;
}
