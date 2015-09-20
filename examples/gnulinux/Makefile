#
all: bloqueante ejemplo evento nobloqueante timeout
	@echo "<<Los programas fueron creados>>"

bloqueante: bloqueante.c com/serial.h com/serielinux.h
	gcc -o bloqueante bloqueante.c 

ejemplo: ejemplo.c com/serial.h com/serielinux.h
	gcc -o ejemplo ejemplo.c -lpthread

evento: evento.c com/serial.h com/serielinux.h
	gcc -o evento evento.c -lpthread

nobloqueante: nobloqueante.c com/serial.h com/serielinux.h
	gcc -o nobloqueante nobloqueante.c 

timeout: timeout.c com/serial.h com/serielinux.h
	gcc -o timeout timeout.c 



clean:
	rm -rf *.o bloqueante ejemplo evento nobloqueante timeout


