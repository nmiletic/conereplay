all: conereplay

conereplay: conereplay.c
	gcc -lpcap -g -o conereplay conereplay.c

clean:
	rm -f conereplay

