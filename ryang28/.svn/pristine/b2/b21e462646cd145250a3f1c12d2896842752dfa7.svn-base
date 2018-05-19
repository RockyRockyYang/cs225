CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi
LD = clang++

all:testimage testscene

testimage : png.o rgbapixel.o image.o testimage.o
	$(LD) png.o rgbapixel.o image.o testimage.o $(LDFLAGS) -o testimage

testscene: png.o rgbapixel.o image.o testscene.o scene.o
	$(LD) png.o rgbapixel.o image.o testscene.o scene.o $(LDFLAGS) -o testscene

image.o: image.h image.cpp
	$(CXX) $(CXXFLAGS) image.cpp

testimage.o: image.h testimage.cpp
	$(CXX) $(CXXFLAGS) testimage.cpp

testscene.o: testscene.cpp
	$(CXX) $(CXXFLAGS) testscene.cpp

scene.o: scene.h scene.cpp
	$(CXX) $(CXXFLAGS) scene.cpp

png.o: png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o: rgbapixel.h rgbapixel.cpp
	$(CXX) $(CXXFLAGS) rgbapixel.cpp


clean: 
	-rm -f *.o testimage testscene
