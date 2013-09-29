#makefile for sfmlgame; some note-to-self notes are listed below

#this tells where GCC looks for headers by default
#`gcc -print-prog-name=cc1plus` -v

#to view invisible files on Mac OSX type next 2 lines into terminal
#defaults write com.apple.Finder AppleShowAllFiles FALSE
#killall Finder

#$(variableName) is similar to a Java EL expression
#for help with makefile variable assignment visit http://stackoverflow.com/questions/448910/makefile-variable-assignment

#export DYLD_LIBRARY_PATH="${DYLD_LIBRARY_PATH}:./SFML-2.0-osx/lib" && export DYLD_FRAMEWORK_PATH="${DYLD_FRAMEWORK_PATH}:./SFML-2.0-osx/Frameworks"

#!/bin/bash

CC := g++
CXXFLAGS := -ggdb -Wall -c
SRCDIR := src
HDIR := ./Headers
SRCEXT := cpp
OBJECTS := Animation.o Character.o FadeAnimation.o GameScreen.o GroundZeroScr.o InputManager.o main.o MenuScreen.o RainDrop.o ScreenManager.o SplashScreen.o TitleScreen.o  

SFMLBASEDIR := ./SFML-2.0-osx
SFMLINCLUDE := ./SFML-2.0-osx/include
SFMLFW := ./SFML-2.0-osx/Frameworks
SFMLLIB := ./SFML-2.0-osx/lib
SFMLLINKFW := -framework sfml-window -framework sfml-graphics -framework sfml-audio -framework sfml-system
SFMLLINK := -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system 

platformer : $(OBJECTS)
	$(CC) build/*.o -o sfmlgame -L$(SFMLLIB) -L$(SFMLFW) $(SFMLLINK) 

Animation.o : src/Animation.cpp $(HDIR)/Animation.hpp
	mkdir -p ./build
	$(CC) $(CXXFLAGS) src/Animation.cpp -o build/Animation.o -I$(SFMLINCLUDE) 

Character.o : src/Character.cpp $(HDIR)/Character.hpp
	$(CC) $(CXXFLAGS) src/Character.cpp -o build/Character.o -I$(SFMLINCLUDE) 

FadeAnimation.o : src/FadeAnimation.cpp $(HDIR)/FadeAnimation.hpp
	$(CC) $(CXXFLAGS) src/FadeAnimation.cpp -o build/FadeAnimation.o -I$(SFMLINCLUDE) 

GameScreen.o : src/GameScreen.cpp $(HDIR)/GameScreen.hpp
	$(CC) $(CXXFLAGS) src/GameScreen.cpp -o build/GameScreen.o -I$(SFMLINCLUDE) 

GroundZeroScr.o : src/GroundZeroScr.cpp $(HDIR)/GroundZeroScr.hpp
	$(CC) $(CXXFLAGS) src/GroundZeroScr.cpp -o build/GroundZeroScr.o -I$(SFMLINCLUDE) 

InputManager.o : src/InputManager.cpp $(HDIR)/InputManager.hpp
	$(CC) $(CXXFLAGS) src/InputManager.cpp -o build/InputManager.o -I$(SFMLINCLUDE) 

MenuScreen.o : src/MenuScreen.cpp $(HDIR)/MenuScreen.hpp
	$(CC) $(CXXFLAGS) src/MenuScreen.cpp -o build/MenuScreen.o -I$(SFMLINCLUDE) 

RainDrop.o : src/RainDrop.cpp $(HDIR)/RainDrop.hpp
	$(CC) $(CXXFLAGS) src/RainDrop.cpp -o build/RainDrop.o -I$(SFMLINCLUDE) 

ScreenManager.o : src/ScreenManager.cpp $(HDIR)/ScreenManager.hpp
	$(CC) $(CXXFLAGS) src/ScreenManager.cpp -o build/ScreenManager.o -I$(SFMLINCLUDE) 

SplashScreen.o : src/SplashScreen.cpp $(HDIR)/SplashScreen.hpp
	$(CC) $(CXXFLAGS) src/SplashScreen.cpp -o build/SplashScreen.o -I$(SFMLINCLUDE) 

TitleScreen.o : src/TitleScreen.cpp $(HDIR)/TitleScreen.hpp
	$(CC) $(CXXFLAGS) src/TitleScreen.cpp -o build/TitleScreen.o -I$(SFMLINCLUDE) 

main.o : src/main.cpp
	$(CC) $(CXXFLAGS) src/main.cpp -o build/main.o -I$(SFMLINCLUDE) 

clean : 
	rm -f build/*.o
