// This Program Illustrates The Use Of write() System Call .

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int iFileDescriptor = 0, iReturnVal = 0;

	char chContentBuffer[] = "This is new added content .\n";
	char chWriteBuffer[sizeof(chContentBuffer)];

	// If File is Opened in Write Mode, We can Write The Contents From 0 Byte Offset .

	iFileDescriptor = open(argv[1], O_RDWR);

	if (iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO OPEN FILE . \n");

		return -1;
	}

	iReturnVal = write(iFileDescriptor, chContentBuffer, sizeof(chWriteBuffer));	
	// Argument 1 : File Descriptor 
	// Argument 2 : Filled Buffer 
	// Argument 3 : Number Of Bytes To Write .
	// write() System Call Returns Number Of Bytes Successfully Write .
	// It Returns -1 if it Fails To Write .
	
	if (iReturnVal != sizeof(chContentBuffer))
	{
		printf("\n ERR : UNABLE TO WRITE CONTENTS . \n");
	}

	lseek(iFileDescriptor, 0, SEEK_SET);

	iReturnVal = read(iFileDescriptor, chWriteBuffer, sizeof(chWriteBuffer));

	printf("\n WRITTEN CONTENTS ARE : \n %s \n", chWriteBuffer);

	close(iFileDescriptor);

	return 0;
}
