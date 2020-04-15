// This progrm demonstrate the use of stat() system call which gives the information of given file

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int iReturnVal = 0;
	struct stat statObj;
	char chFileName[255];

	printf("\n ENTER FILE NAME (IF FILE IS NOT IN CURRENT DIRECTORY THEN ENTER FULL PATH) : ");
	scanf("%s", chFileName);

	// stat() accepts filename as a parameter
	iReturnVal = stat(chFileName, &statObj);

	if (iReturnVal == -1)
	{
		printf("\n ERR : Failed to call stat() \n");

		return -1;
	}

	printf("\n FILE NAME : %s \n", chFileName);
	printf(" FILE SIZE : %ld Bytes \n", statObj.st_size);
	printf(" NUMBER OF BLOCKS ALLOCATED : %ld \n", statObj.st_blocks);
	printf(" BLOCK SIZE OF FILE SYSTEM : %ld \n", statObj.st_blksize);

	if (S_ISREG(statObj.st_mode))
	{
		printf(" FILE %s IS : REGULAR FILE \n", chFileName);
	}
	else if (S_ISCHR(statObj.st_mode))
	{
		printf(" FILE %s IS : CHARACTER SPECIAL FILE \n", chFileName);
	}
	else if (S_ISBLK(statObj.st_mode))
	{
		printf(" FILE %s IS : BLOCK SPECIAL FILE \n", chFileName);
	}
	else if (S_ISDIR(statObj.st_mode))
	{
		printf(" FILE %s IS : DIRECTORY \n", chFileName);
	}
	else if (S_ISFIFO(statObj.st_mode))
	{
		printf(" FILE %s IS : FIFO SPECIAL FILE OR PIPE \n", chFileName);
	}
	else if (S_ISLNK(statObj.st_mode))
	{
		printf(" FILE %s IS : SYMBOLIC LINK \n", chFileName);
	}
	else if (S_ISSOCK(statObj.st_mode))
	{
		printf(" FILE %s IS : SOCKET \n", chFileName);
	}
	else
	{
		printf(" FILE %s IS : UNKNOWN \n", chFileName);
	}


	printf(" ID OF DEVICE : %ld \n", statObj.st_dev);
	printf(" INODE NUMBER OF FILE : %ld \n", statObj.st_ino);
	printf(" NUMBER OF HARD LINKS OF FILE : %ld \n", statObj.st_nlink);

	printf(" PERMISSIONS :  ");
	printf( (S_ISDIR(statObj.st_mode)) ? " d" : " -");
	printf( (statObj.st_mode & S_IRUSR) ? "r" : "-");
	printf( (statObj.st_mode & S_IWUSR) ? "w" : "-");
	printf( (statObj.st_mode & S_IXUSR) ? "x" : "-");
	printf( (statObj.st_mode & S_IRGRP) ? "r" : "-");
	printf( (statObj.st_mode & S_IWGRP) ? "w" : "-");
	printf( (statObj.st_mode & S_IXGRP) ? "x" : "-");
	printf( (statObj.st_mode & S_IROTH) ? "r" : "-");
	printf( (statObj.st_mode & S_IWOTH) ? "w" : "-");
	printf( (statObj.st_mode & S_IXOTH) ? "x" : "-");

	printf("\n USER ID OF OWNER : %d \n", statObj.st_uid);
	printf(" GROUP ID OF OWNER : %d \n\n", statObj.st_gid);

	return 0;
}
