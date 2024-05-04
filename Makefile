BIN := $(HOME)/bin/orly
BIN := ./build/orly

orly: main.c help.h
	$(CC) --std=c11 -Werror -Wall -o $@ $<

help.h: help.txt
	xxd -include $< > $@

$(BIN): orly
	mkdir -p build
	install $< $@
	sudo setcap cap_setuid,cap_setgid=ep $@

@PHONY: install
install: $(BIN)

@PHONY: clean
clean:
	rm -f help.h orly
