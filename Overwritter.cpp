/******************************************************************************

                              DLL Overwritter.
               Overwrite any ROBLOX exploit DLL with custom text.
You may get blacklisted or banned from any of these DLL's! I'm not responsible.

NOTE: Read the documentation before doing anything so you wont ask my ass about anything.

*******************************************************************************/

#include <iostream>
#include <Windows.h>

bool Console_ = true; //Use true if you have braincells and you are smart
bool UsingKrnl_ = true; //If it's krnl then put it to true
const char* ConsoleTitle_ = "Clxyify's DLL Overwritter // By SpeedSterKawaii (Powered By KRNL)";//This would be your console title
const char* Text1_ = "This is powered by clxyify's DLL overwritter!";//Type a line
const char* Text2_ = "Credits to Krnl for the DLL (preventing my death)";//Credit the DLL owner
const char* Text3_ = "Sorry, but you need to get a key, yep sorry.";//Tell them you need a Key
const char* Text4_ = "Anyways here is some krnl text";//Some random shit here

using namespace std;

void ClearLines()//DO NOT USE THIS FUNCTION IT WILL FUCKING KILL KRNL OR ANY OTHER DLL
{
    SetConsoleTitleA("");
    system("cls");
}

void Overwrite()
{
    if (Console_ == true)
    {
        DWORD C;
     	VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &C);
	    *(BYTE*)(&FreeConsole) = 0xC3;
    	AllocConsole();
    	SetConsoleTitleA(ConsoleTitle_);
    	freopen("CONOUT$", "w", stdout);
    	freopen("CONIN$", "r", stdin);
    	HWND ConsoleHandle = GetConsoleWindow();
    	::SetWindowPos(ConsoleHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_HIDEWINDOW);
	    ::ShowWindow(ConsoleHandle, SW_NORMAL);//You can use SW_TOPMOST (although krnl already includes that)
	    
	    std::cout << Text1_ << "\n";
	    std::cout << Text2_ << "\n";
	    std::cout << Text3_ << "\n";
	    std::cout << Text4_ << "\n";
	    
	    if (UsingKrnl_ == true)
	    {
	        system("start https://www.cdn.krnl.ca/getkey.php");
	    }
    }
    else
    {
        MessageBoxA(0, "Error with console bool","WTF bruh",MB_TOPMOST);
        //If you dont know what happened here you need to delete Windows 10 rn
    }
}
