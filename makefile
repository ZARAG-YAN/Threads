CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))
compiler_flags := -Wall -Wextra -pedantic -std=c++11 -c -g
linker_flags := -pthread 

bin/program : $(OBJECTS) ./bin ./inc
	ln -f src/*.hpp ./inc
	$(CC) $(OBJECTS) $(linker_flags) -o $@

obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) $(compiler_flags) $(INC) $< -o $@ 

./inc:
	mkdir -p inc

./bin:
	mkdir -p bin

.PHONY : clean
clean: 
	rm -rf ./obj  ./bin ./inc

ifeq ($(MAKECMDGOALS),)
-include $(DEPENDS)
endif
