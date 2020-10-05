#include "MilWin.h"
#include "Window.h"

/*
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE: // checks for the macro for a close message code
		PostQuitMessage(69); // a helper funtion to post a quit message to the message que
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "Respects");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "Dangerfield");
		}
		break;
	case WM_CHAR: // use for key control
	{
		static std::string title;
		title.push_back((char)wParam);
		SetWindowText(hWnd, title.c_str());
	}
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
	}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam); 
}
*/


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance, // not used
	LPSTR     lpCmdLine, // recieve single strings to process from the cmd line
	int       nCmdShow )
{
	Window wnd(800,300, "First Game Window");

	// message pump
	MSG msg;
	BOOL gResult; // the int defined bool to store GetMessage funtion
	while (gResult = GetMessage(&msg, nullptr, 0, 0) > 0) // gets the message off the message que whiles there is message
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else {
		return msg.wParam; // exit the code with the user defined exit code of 69 instead of 0
	}

	
	return 0;
}