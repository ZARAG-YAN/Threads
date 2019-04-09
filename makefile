all : ./src

./src : 
	mkdir -p bin
	mkdir -p lib
	mkdir -p inc
	mkdir -p obj
	$(MAKE) -C ./src/threads_test/

clean:
	rm -rf ./obj  ./bin ./inc ./lib

.PHONY : ./src clean
