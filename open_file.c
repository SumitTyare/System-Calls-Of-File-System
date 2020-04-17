// This Program Illustrates The open() System Call

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int iFileDescriptor = 0;

	iFileDescriptor = open(argv[1], O_RDONLY);	//argv[1] : Accepting File Name Through Command Line . O_RDONLY : Read Only . 

	if(iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO OPEN FILE \n");
	}
	else
	{
		printf("\n FILE IS SUCCESSFULLY OPENED IN READ ONLY MODE WITH FILE DESCRIPTOR : %d \n", iFileDescriptor);
	}

	
	iFileDescriptor = open(argv[1], O_WRONLY);	//argv[1] : Accepting File Name Through Command Line . O_WRONLY : Write Only .

	if(iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO OPEN FILE \n");
	}
	else
	{
		printf("\n FILE IS SUCCESSFULLY OPENED IN WRITE ONLY MODE WITH FILE DESCRIPTOR : %d \n", iFileDescriptor);
	}


	iFileDescriptor = open(argv[1], O_RDWR);	//argv[1] : Accepting File Name Through Command Line . O_RDWR : Read & Write Mode 

	if(iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO OPEN FILE \n");
	}
	else
	{
		printf("\n FILE IS SUCCESSFULLY OPENED IN READ & WRITE MODE WITH FILE DESCRIPTOR : %d \n", iFileDescriptor);
	}

	close(iFileDescriptor);


	// Uses of other macro while opening a file

	// O_APPEND : Append to the end of file on each write .
	// O_CREAT : Create the file if it doesn't exist .
	// O_EXCL : Generate an error if O_CREAT is also specified and the file already exists . 
	// O_TRUNC : If the file exists and if it is successfully opened for either write-only or read - write, truncate its length to 0 .
	// O_DSYNC : Affects a file's attributes only when they need to be updated to reflect a change in the file's data .
	// O_SYNC : Data and attributes are always updated synchronously .
	// This flags can be OR (|) e.g. open(argv[1] ,O_WRONLY | O_TRUNC)


	return 0;
}

