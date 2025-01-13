#include <iostream>
#include <functional>

using namespace std;

class TV {
private:
    bool isOn;
    int volume;
    int channel;

public:
    TV() : isOn(false), volume(10), channel(1) {}

    void turnOn() {
        isOn = true;
        cout << "TV is turned ON." << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "TV is turned OFF." << endl;
    }

    void volumeUp() {
        if (isOn) {
            volume++;
            cout << "Volume increased to: " << volume << endl;
        }
        else {
            cout << "TV is OFF. Cannot increase volume." << endl;
        }
    }

    void volumeDown() {
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

    void changeChannel(int newChannel) {
        if (isOn) {
            channel = newChannel;
            cout << "Channel changed to: " << channel << endl;
        }
        else {
            cout << "TV is OFF. Cannot change channel." << endl;
        }
    }

    // Function pointers to store callbacks
    void setOnCallback(void (*cb)()) { onCallback = cb; }
    void setOffCallback(void (*cb)()) { offCallback = cb; }
    void setVolumeUpCallback(void (*cb)()) { volumeUpCallback = cb; }
    void setVolumeDownCallback(void (*cb)()) { volumeDownCallback = cb; }
    void setChannelChangeCallback(void (*cb)(int)) { channelChangeCallback = cb; }

    void executeOnCallback() { if (onCallback) onCallback(); }
    void executeOffCallback() { if (offCallback) offCallback(); }
    void executeVolumeUpCallback() { if (volumeUpCallback) volumeUpCallback(); }
    void executeVolumeDownCallback() { if (volumeDownCallback) volumeDownCallback(); }
    void executeChannelChangeCallback(int newChannel) { if (channelChangeCallback) channelChangeCallback(newChannel); }

private:
    void (*onCallback)();
    void (*offCallback)();
    void (*volumeUpCallback)();
    void (*volumeDownCallback)();
    void (*channelChangeCallback)(int);
};

// Functor class for callbacks
class TVActionFunctor {
public:
    void operator()() {
        cout << "Functor callback executed!" << endl;
    }
};

// Main function
int main() {
    TV myTV;

    // Function pointer callbacks
    myTV.setOnCallback([]() { cout << "Function pointer on callback executed!" << endl; });
    myTV.setOffCallback(&TV::turnOff);

    // Functor callback
    TVActionFunctor volumeUpFunctor;
    myTV.setVolumeUpCallback([&volumeUpFunctor]() { volumeUpFunctor(); });

    // Lambda callback
    myTV.setVolumeDownCallback([](int) { cout << "Lambda volume down callback executed!" << endl; });

    myTV.turnOn();
    myTV.volumeUp();
    myTV.volumeDown();
    myTV.turnOff();

    // Balancing Performance and Readability
    // Performance:
    // - Inline functions: Provide performance improvement by eliminating function call overhead.
    // - Functors and lambda expressions: Can be optimized by the compiler as they are often inlineable.
    // Readability:
    // - Function pointers: Provide clear and explicit function signatures, but can make code less expressive.
    // - Functors: Offer named classes, improving readability and maintainability, but can add more classes.
    // - Lambda expressions: Concise and inline, but can be less readable if used excessively or with complex logic.
