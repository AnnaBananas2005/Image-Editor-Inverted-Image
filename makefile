#MAKEFILE

CC=g++ 

CFLAGS= -c -g -Wall -std=c++17 -fpermissive
EXENAME= ImageEditor

$(EXENAME): ImageEditor.o picture.o lodepng.o
	$(CC) ImageEditor.o picture.o lodepng.o -o $(EXENAME)

ImageEditor.o: ImageEditor.cpp ImageEditor-2.h  #soon edit the ImageEditor-2.h name
	$(CC) $(CFLAGS) ImageEditor.cpp
	
picture.o: picture.cpp picture.h
	$(CC) $(CFLAGS) picture.cpp

lodepng.o: lodepng.cpp lodepng.h
    $(CC) $(CFLAGS) lodepng.cpp #says missing seperator

clean: 
	rm *.o $(EXENAME)

run:
    ./$(EXENAME)
