CFLAGS= -g -W -Wall
LIBS= -pthread #-lsocket

#用编译选项定义宏
ifeq ($(test_sock), y)
CFLAGS+= -D TEST_SOCK
endif

all: httpd client

httpd: httpd.c
	gcc $(CFLAGS) -o $@ $< $(LIBS)
	
client: client.c
	gcc $(CFLAGS) -o $@ $<

.PHONY: clean	
clean:
	rm -rf httpd client
