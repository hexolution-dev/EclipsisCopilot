#include <iostream>
#include <Windows.h>

class ScreenReader
{
public:

    // define a function to read the screen pixels
    void ReadScreenPixels(HWND hwnd, int screenWidth, int screenHeight)
    {
        // create a bitmap to store the screen data
        HDC hdcScreen = GetDC(hwnd);
        HDC hdcMemDC = CreateCompatibleDC(hdcScreen);

        HBITMAP hScreen = CreateCompatibleBitmap(hdcScreen, screenWidth, screenHeight);
        HGDIOBJ hOldBitmap = SelectObject(hdcMemDC, hScreen);

        // copy the screen data into the bitmap
        BitBlt(hdcMemDC, 0, 0, screenWidth, screenHeight, hdcScreen, 0, 0, SRCCOPY);

        // create an array to store the RGB values
        int widthInBytes = screenWidth * 4;
        char* data = new char[widthInBytes * screenHeight];

        // copy the RGB values into the array
        GetBitmapBits(hScreen, widthInBytes * screenHeight, data);

        // write the RGB values to the file
        for (int i = 0; i < screenHeight; i++)
        {
            for (int j = 0; j < screenWidth; j++)
            {
                int red = data[i * widthInBytes + j * 4];
                int green = data[i * widthInBytes + j * 4 + 1];
                int blue = data[i * widthInBytes + j * 4 + 2];
            }
        }

        SelectObject(hdcMemDC, hOldBitmap);
        DeleteDC(hdcMemDC);
        ReleaseDC(hwnd, hdcScreen);
        DeleteObject(hScreen);
        delete[] data;
    }
};
