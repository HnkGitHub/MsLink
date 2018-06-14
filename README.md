# MsLink
Create and Delete Symbolic Links for Windows
This projects contains the C code to create and delete symbolic links using the Windows API CreateSymbolicLink. Since windows Vista users have had something of their own symbolic link function, a function that had once only been available to the users of Linux. And if you´re familiar with MinGW or Cygwin, then you may have used their clone of the Unix ln function. However, instead of making a real symbolic link, these clones just copy every file and directory. Not what you were expecting.
This simple project should provide two executables to use to make and delete symbolic links for files or directories: msln.exe and DlLn.exe.
