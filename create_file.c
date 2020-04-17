// This Program Illustrates The Create a New File If Not Exists Using creat() System Call .

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int iFileDescriptor = 0;

	iFileDescriptor = creat(argv[1], 0x777);	// argv[1] : Accepting File Name Through Command Line . 0x777 : "rwx rwx rwx" (Permissions)

	if(iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO CREATE FILE \n");
	}
	else
	{
		printf("\n FILE IS SUCCESSFULLY CREATED WITH FILE DESCRIPTOR : %d \n", iFileDescriptor);
	}

	close(iFileDescriptor);		// Closing The File
	
	return 0;

}
