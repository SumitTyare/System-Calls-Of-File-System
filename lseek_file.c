// This Program Illustrates The Use Of lseek() System Call .

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int iFileDescriptor = 0, iFileOffset = 0;

	iFileDescriptor = open(argv[1], O_RDONLY);
	
	if (iFileDescriptor == -1)
	{
		printf("\n ERR : UNABLE TO OPEN FILE \n");
		
		return -1;
	}

	// SEEK_SET : Starting Byte Offset Of File .
	// SEEK_CUR : Current Byte Offset Of File .
	// SEEK_END : Last Byte Offset Of File .
	
	iFileOffset = lseek(iFileDescriptor, 0, SEEK_SET);	// 2nd Argument is Number Of Byte Offset . Negative Number is For Backward Traversing .
	printf("\n STARTING BYTE OFFSET OF FILE IS: %d \n", iFileOffset);
	
	iFileOffset = lseek(iFileDescriptor, 0, SEEK_END);	
	printf("\n AFTER TRAVERSING TILL LAST, BYTE OFFSET OF FILE IS: %d \n", iFileOffset);	// 2nd Argument is Number Of Byte Offset . Negative Number is For Backward Traversing .
	
	iFileOffset = lseek(iFileDescriptor, 50, SEEK_SET);	// 2nd Argument is Number Of Byte Offset . Negative Number is For Backward Traversing .
	printf("\n AFTER TRAVERSING FROM STARTING BYTE OFFSET BY 50, BYTE OFFSET IS: %d \n", iFileOffset);	// 2nd Argument is Number Of Byte Offset . Negative Number is For Backward Traversing .
	
	iFileOffset = lseek(iFileDescriptor, -10, SEEK_CUR);
	printf("\n AFTER TRAVERSING BACKWARD BY 10 FROM CURRENT BYTE OFFSET IS: %d \n", iFileOffset);		// 2nd Argument is Number Of Byte Offset . Negative Number is For Backward Traversing .

	iFileOffset = lseek(iFileDescriptor, 100, SEEK_CUR);
	printf("\n AFTER TRAVERSING FORWARD BY 100 FROM CURRENT BYTE OFFSET IS: %d \n\n", iFileOffset);		// 2nd Argument is Number Of Byte Offset . Negative Number is For Backward Traversing .
	
	close(iFileDescriptor);

	return 0;
}
