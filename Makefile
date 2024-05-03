fk: main.c
	$(CC) --std=c11 -Werror -Wall -o $@ $<
	sudo setcap cap_setuid,cap_setgid=ep $@
