compile:
	g++ -c -std=c++11 Register.cpp
	g++ -c -std=c++11 Retirement.cpp
	g++ -c -std=c++11 Loan.cpp
	g++ -std=c++11 Clementine.cpp Register.cpp Retirement.cpp Loan.cpp -o Clementine.out

run:
	./Clementine.out

clean:
	rm *.out
	rm *.o
