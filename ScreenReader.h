#include <iostream>
#include <Windows.h>
#include <vector>

#include "MakePPMImage.h";

// Class to read the pixels of the screen and create a PPM image
class ScreenReader
{
public:
    // Reads the pixels of the screen and creates a PPM image
    void ReadScreenPixels(HWND hwnd, int screenWidth, int screenHeight)
    {
        // Get the device context of the screen
        HDC hdcScreen = GetDC(hwnd);
        // Create a compatible device context
        HDC hdcMemDC = CreateCompatibleDC(hdcScreen);

        // Create a compatible bitmap for the screen
        HBITMAP hScreen = CreateCompatibleBitmap(hdcScreen, screenWidth, screenHeight);
        // Select the bitmap into the compatible device context
        HGDIOBJ hOldBitmap = SelectObject(hdcMemDC, hScreen);

        // Copy the screen into the compatible device context
        BitBlt(hdcMemDC, 0, 0, screenWidth, screenHeight, hdcScreen, 0, 0, SRCCOPY);

        // Get the bitmap data in bytes
        int widthInBytes = screenWidth * 4;
        char* data = new char[widthInBytes * screenHeight];

        // Copy the bitmap data into the buffer
        GetBitmapBits(hScreen, screenWidth * 4 * screenHeight, data);

        // Create a PPM image from the bitmap data (commented out for now)
        // MakePPMImage ppm;
        // ppm.createPPMImage(data, screenWidth, screenHeight, widthInBytes);

        // Clean up
        SelectObject(hdcMemDC, hOldBitmap);
        DeleteDC(hdcMemDC);
        ReleaseDC(hwnd, hdcScreen);
        DeleteObject(hScreen);

        delete[] data;
    }
};
