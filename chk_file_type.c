// Program To Find The Type Of a File

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat statBuffer;
	char chFileName[255];
	
	printf("\n ENTER FILE NAME : ");
	scanf("%s", chFileName);

	if (stat(chFileName, &statBuffer) < 0)
	{
		printf("\n ERR : Unable To Retrive Statistics Of File \n");

		return -1;
	}

	// There are macros defined which checks the file type . If file type is Match then it returns TRUE

	if (S_ISREG(statBuffer.st_mode))
	{
		printf("\n %s IS : REGULAR FILE \n", chFileName);
	}
	else if (S_ISDIR(statBuffer.st_mode))
	{
		printf("\n %s IS : DIRECTORY \n", chFileName);
	}
	else if (S_ISCHR(statBuffer.st_mode))
	{
		printf("\n %s IS : CHARACTER SPECIAL FILE \n", chFileName);
	}
	else if (S_ISBLK(statBuffer.st_mode))
	{
		printf("\n %s IS : BLOCK SPECIAL FILE \n", chFileName);
	}
	else if (S_ISSOCK(statBuffer.st_mode))
	{
		printf("\n %s IS : SOCKET \n", chFileName);
	}
	else if (S_ISLNK(statBuffer.st_mode))
	{
		printf("\n %s IS : SYMBOLIC LINK \n", chFileName);
	}
	else if (S_ISFIFO(statBuffer.st_mode))
	{
		printf("\n %s IS : FIFO \n", chFileName);
	}
	else
	{
		printf("\n %s IS : UNKNOWN FILE TYPE \n", chFileName);
	}

	return 0;
}
