compile: dirinfo.c
	gcc -o dirinfo dirinfo.c

run: dirinfo
	./dirinfo

clean:
	rm dirinfo
	rm *~
