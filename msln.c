// msln.c
#include <windows.h>
#include <VersionHelpers.h>
#include <stdio.h>

#ifndef SYMBOLIC_LINK_FLAG_ARCHIVE
#define SYMBOLIC_LINK_FLAG_ARCHIVE 0
#endif

#ifndef SYMBOLIC_LINK_FLAG_DIRECTORY
#define SYMBOLIC_LINK_FLAG_DIRECTORY 1
#endif

#ifndef SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE
#define SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE 2
#endif

// Prototypes
void PrintErrMsg (LPSTR) ;

int main(int argc, char *argv[])
{
	DWORD dwAttr ;
	DWORD dwFlagFile, dwFlagDir ;
	// Test for Windows Vista or Greater
	if (!IsWindowsVistaOrGreater())
	{
		printf("Windows Version must be Vista or greater\n") ;
		ExitProcess(0) ;
	}
	
	// Set FLAGS for CreateSymbolicLink Function.
	if (IsWindows10OrGreater())
	{
		dwFlagFile = SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE ;
		dwFlagDir = SYMBOLIC_LINK_FLAG_DIRECTORY | SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE ;
	}
	else
	{
		dwFlagFile = SYMBOLIC_LINK_FLAG_ARCHIVE ;
		dwFlagDir = SYMBOLIC_LINK_FLAG_DIRECTORY ;
	}

	// Test for 2 arguments
	if (argc != 3)
	{
		printf ("Usage: msln [symbolic link] [target]\n") ;
		ExitProcess() ;
	}
	
		
	// Test for ARCHIVE or DIRECTORY Attribute
	dwAttr = GetFileAttributes(argv[2]) ;
	if ( (dwAttr & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
	{
		if (CreateSymbolicLinkA(argv[1], argv[2], dwFlagFile))
		{
			printf("Symbolic Link %s created as a file\n", argv[1]) ;
		}
		else
		{
			PrintErrMsg ("Create SymLink File") ;
		}
	}
	else
	{
		if ( (dwAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
			if (CreateSymbolicLinkA(argv[1], argv[2], dwFlagDir))
			{
				printf("Symbolic Link %s created as a Directory\n", argv[1]) ;
			}
			else
			{
				PrintErrMsg ("Create SymLink Directory") ;
			}
	}
	return 0 ;
}

void PrintErrMsg (LPSTR lpszFunction) 
{
	LPVOID lpBuffer ;
	DWORD dwError = GetLastError() ;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwError,
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&lpBuffer,
			60,
			NULL
		     ) ;

	printf("%s\n%sError: #%d\n", lpszFunction, (char *)lpBuffer, dwError) ;
	LocalFree(lpBuffer) ;
	ExitProcess(dwError) ;
}


