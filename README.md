# MsLink
Create and Delete Symbolic Links for Windows.
This projects contains the C code to create and delete symbolic links using the Windows API CreateSymbolicLink and various file APIs. Since windows Vista users could use a symbolic link function, a function once only available to Linux users. And if you´re familiar with MinGW or Cygwin, then you may have used their clone of the Unix ln function. However, instead of making a real symbolic link, these clones just copy every file and directory. Not what you were expecting.
This simple project should provide two executables, msln.exe and DlLn.exe, to create or delete symbolic links. Use the command line compiler to compile and link the source files.
