// This Program Illustrates The Use Of read() System Call .

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int iFileDescriptor = 0; 
	char chBuffer[1024];

	// If File is Opened in READ Mode, We Can Read The Contents From 0 Byte Offset
	
	iFileDescriptor = open(argv[1], O_RDONLY);

	if (iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO OPEN FILE \n");

		return -1;
	}

	// We Can READ The Contents of File By read() System Call .
	// Parameters of read() System Call => 1 : File Descriptor, 2 : Empty Buffer, 3 : Number Of Bytes To Read .

	// Loop For Reading Whole File
	printf("\n READ CONTENTS ARE : \n");
	while(read(iFileDescriptor, chBuffer, sizeof(chBuffer)))
	{
		printf("%s", chBuffer);
	}
	
	close(iFileDescriptor);

	return 0;
}
