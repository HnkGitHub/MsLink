#include <windows.h>
#include <stdio.h>

#ifndef SYMBOLIC_LINK_FLAG_DIRECTORY
#define SYMBOLIC_LINK_FLAG_DIRECTORY 1
#endif

int main(int argc, char *argv[])
{
	DWORD dwAttr ;
	// Test for ARCHIVE or DIRECTORY Attribute
	dwAttr = GetFileAttributes(argv[2]) ;
	if ( (dwAttr & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
	{
		if (CreateSymbolicLinkA(argv[1], argv[2], SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE))
		{
			printf("Symbolic Link %s created as a file\n", argv[1]) ;
		}	
	}
	else
	{
		if ( (dwAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
			if (CreateSymbolicLinkA(argv[1], argv[2], SYMBOLIC_LINK_FLAG_DIRECTORY | SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE))
			{
				printf("Symbolic Link %s created as a Directory\n", argv[1]) ;
			}
	}
	return 0 ;
}
