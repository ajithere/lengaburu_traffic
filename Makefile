CC=g++

MYPROGRAM=lengaburu

TEST_EXE=test

PROGRAM_SOURCE=lengaburuRouteOptimizer.cc lengaburuTrafficEngine.cc trafficEngine.cc vehicle.cc lengaburuOrbit.cc

TEST_SOURCE=./tests/lengaburuOrbitTest.cc ./tests/vehicleTest.cc ./tests/lengaburuRouteOptimizerTest.cc

MYINCLUDES= -I. -I./tests -I./tests/Catch/include

lengaburu: $(PROGRAM_SOURCE) main.cc 
	$(CC) -o $(MYPROGRAM) $(PROGRAM_SOURCE) main.cc $(MYINCLUDES)

test: $(TEST_SOURCE) $(PROGRAM_SOURCE)
	$(CC) -o $(TEST_EXE) $(TEST_SOURCE) $(PROGRAM_SOURCE) $(MYINCLUDES)

all: $(MYPROGRAM) $(TEST_EXE)

clean:
	rm -f $(MYPROGRAM) $(TEST_EXE)
