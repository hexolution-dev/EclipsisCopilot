#include "KeyPress.h"
#include "ScreenReader.h"
#include <chrono>

using namespace std::chrono;

int main()
{
	// find the window with the title "Roblox" 
	HWND robloxClient = FindWindowA(NULL, "Roblox");

	// return -1 if there is no window with the title "Roblox"
	if (!robloxClient) { return -1; }

	// create a RECT to store the window size
	RECT rect;
	// get the window size using GetWindowRect
	GetWindowRect(robloxClient, &rect);

	// create a ScreenReader object
	ScreenReader sr;

	// get the start time of the program
	auto start = high_resolution_clock::now();

	// get the screen size
	int screenWidth = rect.right - rect.left;
	int screenHeight = rect.bottom - rect.top;

	// read the screen pixels
	sr.ReadScreenPixels(robloxClient, screenWidth, screenHeight);

	// get the end time of the program
	auto stop = high_resolution_clock::now();
	// calculate the total duration
	auto duration = duration_cast<microseconds>(stop - start);

	// print the total duration
	std::cout << "took: " << duration << std::endl;

	return 0;
}
