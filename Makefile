all: obj link

obj:
	g++ -c linked_list.cpp

link:
	g++ -o linked_list linked_list.o

clean:
	rm *.o
	rm ./linked_list
