sortDriver: printlist.o sortDriver.o bubble.o quick.o comparator.o
	g++ sortDriver.o printlist.o comparator.o bubble.o quick.o -I../../include -L../../lib -lnowic_mac -o sortDriver
	
sortDriver.o: sortDriver.cpp
	g++ -c -std=c++11 -Wall sortDriver.cpp -I../../include

comparator.o: comparator.cpp
	g++ -c -std=c++11 -Wall comparator.cpp

printlist.o: printlist.cpp
	g++ -c -std=c++11 -Wall printlist.cpp
	
bubble.o: bubble.cpp
	g++ -c -std=c++11 -Wall bubble.cpp -I../../include
	
quick.o: quick.cpp 
	g++ -c -std=c++11 -Wall quick.cpp -I../../include
	
clean:
	rm -f *.o sortDriver.exe sortDriver