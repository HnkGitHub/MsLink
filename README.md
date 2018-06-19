# MsLink
Create and Delete Symbolic Links for Windows.
This projects contains the C code to create and delete symbolic links using the Windows API CreateSymbolicLink and various file APIs. Since windows Vista users could use a symbolic link function, a function once only available to Linux users. And if you´re familiar with MinGW or Cygwin, then you may have used their clone of the Unix ln function. However, instead of making a real symbolic link, these clones just copy every file and directory. Not what you were expecting.
This simple project should provide two executables, msln.exe and DlLn.exe, to create or delete symbolic links, respectively. Use the command line compiler to compile and link the source files.

A Windows 10 user must meet at least one of the following conditions to be able to use the CreateSymbolicLink function: (1) Run as Adminstrator, (2) Run as a user with administrator privileges, or (3) if a user with non-adminstrator rights must have the Create Symbolic Link privilege added through the Group Policy Editor. Run "gpedit.msc" as an Adminstrator to elevate the privilege level of a non administrator.
