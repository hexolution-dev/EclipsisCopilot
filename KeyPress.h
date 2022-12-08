#include <Windows.h>

//This class is used to press a key on the keyboard for a given duration.
class KeyPress {
public:
    //This function is used to press a key for a given duration.
    //It takes two parameters, the key code and the duration.
    int pressKey(int code, int duration) {
        //Create a new INPUT called KEY_W.
        INPUT KEY_W;

        //Set the type of the INPUT to keyboard.
        KEY_W.type = INPUT_KEYBOARD;
        //Set the flags of the INPUT to scan code.
        KEY_W.ki.dwFlags = KEYEVENTF_SCANCODE;
        //Set the scan code of the INPUT.
        KEY_W.ki.wScan = code;

        //Send the input to the computer.
        SendInput(1, &KEY_W, sizeof(INPUT));

        //Sleep for the given duration in milliseconds.
        Sleep(duration);

        //Set the flags of the INPUT to scan code and keyup.
        KEY_W.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

        //Send the input to the computer.
        SendInput(1, &KEY_W, sizeof(INPUT));

        return 1;
    }
};
