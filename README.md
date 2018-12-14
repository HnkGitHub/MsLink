# MsLink
Create and Delete Symbolic Links for Windows.
This projects contains the C code to create and delete symbolic links using the Windows API CreateSymbolicLink and various file APIs. Since windows Vista users could use a symbolic link function, a function once only available to Linux users. And if you´re familiar with MinGW or Cygwin, then you may have used their clone of the Unix ln function. However, instead of making a real symbolic link, these clones just copy every file and directory. Not what you were expecting.
This simple project should provide two executables, msln.exe and DlLn.exe, to create or delete symbolic links, respectively. Use the command line compiler to compile and link the source files.

A Windows 10 user must meet at least one of the following conditions to be able to use the CreateSymbolicLink function: (1) Run as Adminstrator, (2) Run as a user with administrator privileges, or (3) if a user with non-adminstrator rights must have the Create Symbolic Link privilege added through the Group Policy Editor. Run "gpedit.msc" as an Adminstrator to elevate the privilege level of a non administrator.

To use the Group Policy Editor you must be a member of the Administrator's group or just run gpedit.msc from a Run as Administrator command prompt. You may use the (Windows Command + R) on your Windows keyboard and type in gpedit.msc in the Open input box. You should find the setting to change in the User Rights Assignment section: e.g., Local Computer Policy\Computer Configuration\Windows Settings\Security Settings\Local Policies\User Rights Assignment\Create Symbolic Links. Add the users you wish to have this privilege to this section. 

Earlier versions of Windows, e.g. Vista, Windows 7, only allow the user to run this function as Administrator or a standard user with the privilege of creating symbolic links added in the Group Policy Editor. A user belonging to the Administrator's group will fail in its attempt to run this program unless specifically switching to a command prompt run as Administrator. Also, the 'SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE' flag does not run on Vista, or Windows 7. Most likely the flag will not run on Windows 8, but has not been verified. The msln.c file has been coded to take this into account and should run on all operating systems since Windows Vista. Apparently, the SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE flag allows a user in the Adminstrator group to run the program successfully in Windows 10 or later. Not possible with Vista or Windows 7.

To compile this program you must use at least Visual Studio 2013, or possibly Visual Studio 2012, as the VersionHelpers.h header file does not appear in earlier versions.


