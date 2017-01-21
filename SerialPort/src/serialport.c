#include <stdio.h>
#include <windows.h>
#include "serialport.h"

void ErrorExit(LPTSTR lpszFunction) 
{ 

    LPVOID lpMsgBuf;

    // Retrieve the system error message for the last-error code
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    printf("%s failed with error %lu: %s", lpszFunction, dw, (char*)lpMsgBuf);

    LocalFree(lpMsgBuf);
    ExitProcess(dw); 
}
HANDLE openSP(LPCSTR portname,enum Baudrate baudrate, enum Stopbits stopbits, enum Paritycheck parity)
{
	DWORD  accessdirection =GENERIC_READ | GENERIC_WRITE;
	HANDLE hSerial = CreateFile(portname,
		accessdirection,
		0,
		0,
		OPEN_EXISTING,
		0,
		0);
	if (hSerial == INVALID_HANDLE_VALUE) {
		ErrorExit("CreateFile");
	}
	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams)) {
		 ErrorExit("GetCommState");
	}
	dcbSerialParams.BaudRate=baudrate;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=stopbits;
	dcbSerialParams.Parity=parity;
	if(!SetCommState(hSerial, &dcbSerialParams)){
		 ErrorExit("SetCommState");
	}
	COMMTIMEOUTS timeouts={0};
	timeouts.ReadIntervalTimeout=50;
	timeouts.ReadTotalTimeoutConstant=50;
	timeouts.ReadTotalTimeoutMultiplier=10;
	timeouts.WriteTotalTimeoutConstant=50;
	timeouts.WriteTotalTimeoutMultiplier=10;
	if(!SetCommTimeouts(hSerial, &timeouts)){
		ErrorExit("SetCommTimeouts");
	}
	return hSerial;
}
DWORD readSP(HANDLE hSerial, char * buffer, int buffersize)
{
    DWORD dwBytesRead = 0;
    if(!ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL)){
        ErrorExit("ReadFile");
    }
    return dwBytesRead;
}
DWORD writeSP(HANDLE hSerial, char * data, int length)
{
	DWORD dwBytesRead = 0;
	if(!WriteFile(hSerial, data, length, &dwBytesRead, NULL)){
		ErrorExit("WriteFile");
	}
	return dwBytesRead;
}
void closeSP(HANDLE hSerial)
{
	CloseHandle(hSerial);
}
