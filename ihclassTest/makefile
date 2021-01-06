
all: intelhextest
 
# $@ matches the target; $< matches the first dependent
intelhextest: intelhextest.o intelhexclass.o
	g++ -g -Og -o $@ intelhextest.o intelhexclass.o

intelhextest.o: intelhextest.cpp
	g++ -g -Og -c $<

intelhexclass.o: ../intelhex_class/intelhexclass.cpp
	g++ -g -Og -c $<
     
test:
	$(shell ${PWD}/runAllTests.sh)

clean:
	-rm -f intelhextest intelhextest.o intelhexclass.o
