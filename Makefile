all:
	g++ src/fileview.c 	-o bin/fileview
	g++ src/hello.c 	-o bin/hello
	g++ src/forloop.c 	-o bin/forloop

clean:
	rm bin/*.*
