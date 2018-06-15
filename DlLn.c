// DlLn.c
// Delete Symbolic Links
// Use Microsoft Visual C++
#include <windows.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	DWORD dwAttr ;
	// Test for the presence of an argument
	if (!argv[1])
	{
		printf ("Usage: dlln [Symbolic Link]\n") ;
		return 0 ;
	}

	// Test File attributes to verify the file is a valid symbolic link before proceeding
	dwAttr = GetFileAttributes(argv[1]) ;
	if ((dwAttr & FILE_ATTRIBUTE_REPARSE_POINT) != FILE_ATTRIBUTE_REPARSE_POINT)
	{
		printf ("%s is not a symbolic link\n", argv[1]) ;
		return 0 ;
	}
	else
		
	// Pseudo Logic:
	// if link refers to a file, use DeleteFile, else use RemoveDirectory API.
	{
		if ((dwAttr & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE) 
		{
			if (DeleteFile(argv[1]))
				printf("Symbolic Link File %s deleted.\n", argv[1]) ;
		}
		else	
		{
			if ((dwAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) 
			{
				if (RemoveDirectory(argv[1]))
					printf("Symbolic Link Directory %s deleted\n", argv[1]) ;
			}
		}
	}
				
	return 0 ;
}
