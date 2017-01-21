all: 	fileview hello forloop myHeaderMain

fileview:
	gcc src/fileview.c 	-o bin/fileview

hello:
	gcc src/hello.c 	-o bin/hello

forloop:
	gcc src/forloop.c 	-o bin/forloop

myHeaderMain:
	gcc src/myHeaderMain.c src/myHeader.c -o bin/myHeaderMain

.PHONY: clean
clean:
	rm -f bin/*
