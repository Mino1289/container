CXX = gcc
CFLAGS = -Wall -Werror -fpic -pedantic
LIBSDIR = -L.
INCLUDEDIR = -I.

LIBCORENAME = container

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -ggdb -DDEBUG
endif

ifeq ($(OS), Windows_NT)
	($warning Windows build is not supported yet)
#	EXPORT = export.bat
#	LIBTARGET :=$(LIBCORENAME:=.dll)
#	CLEANCMD = @del /q *.o *.dll *.exe *.so
else
	EXPORT = sh export.sh
	LIBTARGET := lib$(LIBCORENAME:=.so)
	LIBSDIR += -L/usr/lib
	INCLUDEDIR += -I/usr/include
	CLEANCMD = rm -rf build/
	P = -p
endif

SOURCEDIR=.
BUILDDIR=build

SOURCES = $(wildcard $(SOURCEDIR)/*.c)
OBJECTS = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))


EXECUTABLE = main
LIBCORENAME = container
LIBTARGET:=lib$(LIBCORENAME:=.so)

all: dir $(OBJECTS) $(LIBTARGET) $(EXECUTABLE)

dir:
	@mkdir $(BUILDDIR) $(P)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(LIBTARGET)
	$(CXX) $(CFLAGS) $(INCLUDEDIR) $(LIBSDIR) $(BUILDDIR)/$(EXECUTABLE:=.o) -o $(EXECUTABLE) -l$(LIBCORENAME) -lm

$(LIBTARGET) : $(OBJECTS)
	$(CXX) $(CFLAGS) -shared $(filter-out $(BUILDDIR)/main.o,$(OBJECTS)) -o $(LIBTARGET)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CFLAGS) -c -o $@ $<

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

clean: 
	$(CLEANCMD)
	@echo CLEAN