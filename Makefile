PROJECT = sloap

DEBUG = 0

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin

CC = gcc
CFLAGS += -std=c99 -pedantic -Wall -Wextra -Werror \
          -Wimplicit-function-declaration -Wno-main -Wno-uninitialized \
	  -D _DEFAULT_SOURCE
LDFLAGS += 

SRCDIR = src
SRC = $(SRCDIR)/$(PROJECT).c
OBJ = term.o

ifeq ($(DEBUG),0)
    CFLAGS  += -O2
else
    CFLAGS  += -g
    LDFLAGS += -g
endif

all: $(PROJECT)

%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	@echo \  CC $<
	@$(CC) $(CFLAGS) -c $<

$(PROJECT): $(SRC) $(OBJ)
	@echo \  CC $<
	@$(CC) $(SRC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(PROJECT)

clean:
	@echo \  RM $(PROJECT)
	@rm -f $(PROJECT) *.o

install: all
	@echo \  IN $(DESTDIR)$(BINDIR)/$(PROJECT)
	@install -Dm755 $(PROJECT) $(DESTDIR)$(BINDIR)/$(PROJECT)

uninstall:
	@echo \  RM $(DESTDIR)$(BINDIR)/$(PROJECT)
	@rm -f $(DESTDIR)$(BINDIR)/$(PROJECT)

.PHONY: clean install uninstall

