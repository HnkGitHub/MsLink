CC = cl
LINK = link
AS = ml64

!ifdef DEBUG
CFLAGS = /Zi /nologo
LFLAGS = /DEBUG /NOLOGO
!else
CFLAGS = /nologo
LFLAGS = /RELEASE /NOLOGO
!endif

LIBS = kernel32.lib

all : dlln.exe msln.exe

clean :
	del dlln.obj
	del dlln.exe
	del msln.obj
	del msln.exe

dlln.exe : dlln.obj
	$(LINK) $(LFLAGS) dlln.obj $(LIBS)

msln.exe : msln.obj
	$(LINK) $(LFLAGS) msln.obj $(LIBS)
