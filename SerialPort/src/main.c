// (c) Muthanna A. Attyah 2017
// Writing/Reading a serial port

#include <stdio.h>
#include "serialport.h"

int main(void)
{
	//Open Port
	puts("Connecting to serial port");
	HANDLE h = openSP("COM1",B9600,one,off);

	char sendbuffer[] = "Hello this is muthanna...any one there!";
	char readbuffer[100];

	//Write test
	puts("Writing to serial port");
	int bytesWritten = writeSP(h,sendbuffer,strlen(sendbuffer));
	printf("%d Bytes were written\n",bytesWritten);

	//Read test
	puts("Reading to serial port");
	int bytesRead = readSP(h,readbuffer,99);
	readbuffer[bytesRead]=0;
	printf("%d Bytes were read:%s\n",bytesRead,readbuffer);

	//Close Port
	closeSP(h);
    return 0;
}
