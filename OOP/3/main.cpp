#include "sleepers.h"
#include <windows.h>

int MapWidth = 20;

int ScreenWidth = 500;
int ScreenHeight = 500;

int main()
{
	// Create screen buffer
	char *screen = new char[ScreenWidth * ScreenHeight];
	HANDLE Console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,
											   NULL, CONSOLE_TEXTMODE_BUFFER,
											   NULL);
	SetConsoleActiveScreenBuffer(Console);
	DWORD dwBytesWritten = 0;

	// init map
	wstring map;
	map += L"####################";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"#..................#";
	map += L"####################";

	while (1)
	{
		// Display map
		for (int nx = 0; nx < MapWidth; nx++)
			for (int ny = 0; ny < MapWidth; ny++)
				screen[(ny+1)*ScreenWidth + nx] = map[ny * MapWidth + nx];

		// Display Frame
		screen[ScreenWidth * ScreenWidth - 1] = '\0';
		WriteConsoleOutputCharacter(Console, screen, ScreenWidth * ScreenHeight,
									{0, 0}, &dwBytesWritten);
	}

	return 0;
}
