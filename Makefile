all:
	gcc -o release\wms.exe wms.c
clean:
	del release\wms.exe