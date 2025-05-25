#MAKEFILE

CC=g++ 

CFLAGS= -c -g -Wall -std=c++17 -fpermissive
EXENAME= ImageEditor

$(EXENAME): ImageEditor.o picture.o lodepng.o main.o
	$(CC) ImageEditor.o picture.o lodepng.o main.o -o $(EXENAME)

ImageEditor.o: ImageEditor.cpp ImageEditor-2.h  
	$(CC) $(CFLAGS) ImageEditor.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
picture.o: picture.cpp picture.h
	$(CC) $(CFLAGS) picture.cpp

lodepng.o: lodepng.cpp lodepng.h
	$(CC) $(CFLAGS) lodepng.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)
