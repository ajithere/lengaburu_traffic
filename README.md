############## PROBLEM CONTEXT ################################################

2 Problems as given in https://www.geektrust.in/coding-problem/backend/traffic
have been addressed here. 
First Problem involves finding the most optimised orbits between start & destination
Second Problem involves finding optimised route which covers 2 destination apart from the start location

############## DESIGN DETAILS ############################################

** Following class Hierarchy has been created **
	Orbit (orbit.h)  -----> Lengaburu Orbits (lengaburuOrbit.h and cc)
	Vehicle (vehicle.h and cc) 		-------> Car (supercarVehicle.h)
						-------> Tuk Tuk (tuktukVehicle.h)
						-------> Bike (bikeVehicle.h) 
	Route Optimization(routeOptimizer.h)	-------> Lengaburu Route Optimization(lengaburuRouteOptimization.h and cc)
	Traffic Engine(trafficEngine.h and cc)	-------> Lengaburu Traffic Engine(lengaburuTrafficEngine.h and cc)
	
Bridge Design Pattern used extensively where abstractions and implementations have been kept seperate
That is the reason for having abstractions for Orbit, Vehicle, RouteOptimization and Traffic Engine which can have 
varying implementations.

Factory method used in Traffic Engine where child classes decide which concrete implementation of optimizer is supposed to
be used.
A varying style of Factory method is also used in Vehicle implementatio where caller uses Vehicle's static method to get 
any type of vehicle (without knowing which concrete type is instantited)

Decoupling using dependency injection has been tried as much as possible. Vehicle, orbit etc is injected into Optimization
classes.

Traffic Engine - The basic idea is to have a consumer who creates various parts needed in traffic mamagement like
orbit, vehicles and optimizer. While flow is fixed, each of the implementation can be varied in its derived classes

Route Optimization - Lengaburu can have one optimization logic and something like Ledhi can be added tomorrow. This
design allows the same.

Factory method (like one created for Vehicle) not done purposely for classes like Traffic Engine, Optimization and 
Orbit as there is presently only one child implementation. At this point of time its YAGNI.
It Can be easily refactored later when needed.

Catch - Used Behaviour Driven Development (BDD) for testing.      
STL - Used Standard Template Library for basic containers, string etc.
Makefile - used basic makefile for compilation

############## HOW TO RUN ################################################

1. Run make (or make all) command and it will create the exe called lengaburu
2. Execute by running ./lengaburu 1 for Problem -1 and ./lengaburu 2 for Problem -2
3. Provide inputs as asked and verify the final output

############## HOW TO RUN TEST CASES #####################################

1. Run make runtest (or make all) command and it will create the exe called runtest
2. Execute by running ./runtest
3. Verify that all test cases pass.

############## HOW TO CLEAN AND BUILD ALL ##################################

1. Run make clean. It will remove the executables of main program and test
2. Run make all. It will compile and create exe for both the main program and test.
