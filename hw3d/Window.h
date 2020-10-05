#pragma once
#include "MilWin.h"

class Window
{
private:
	//singeton for managing registration/deregistration pf window class
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "Milson Direct3D Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	Window(int width, int height, const char* name) noexcept; //constructor for basic window data, addresses client region w & h mismatch with calculation
	~Window();	// destructor
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
private:
	// static function to register win.api callbacks
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); // static to set up window callback, passes to msgthunk if already set up
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); // actual message handling
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
private:
	int width;
	int height;
	HWND hWnd;
};

