
#
# Makefile for P2 (submitted version)
# COSC 052
# Fall 2018
#

DRIVER_NAME = main
SUBMIT_NAME = submit
LIBRARY_NAME = agLibrary


a.out: $(DRIVER_NAME).o vehicleLog.o vehicle.o DateTime.o exceptions.o
	g++ -std=c++11 $(DRIVER_NAME).o vehicleLog.o vehicle.o DateTime.o exceptions.o

$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h vehicleLog.h vehicle.h DateTime.h
	g++ -std=c++11 -c $(DRIVER_NAME).cpp

vehicleLog.o: vehicleLog.cpp vehicleLog.h vehicle.h exceptions.h
	g++ -std=c++11 -c vehicleLog.cpp

vehicle.o: vehicle.cpp vehicle.h DateTime.h
	g++ -std=c++11 -c vehicle.cpp

DateTime.o: DateTime.cpp DateTime.h
	g++ -std=c++11 -c DateTime.cpp

exceptions.o: exceptions.cpp exceptions.h
	g++ -std=c++11 -c exceptions.cpp


.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(DRIVER_NAME).cpp $(DRIVER_NAME).h vehicleLog.cpp vehicleLog.h vehicle.cpp vehicle.h exceptions.cpp exceptions.h DateTime.cpp DateTime.h Makefile

clean:
	rm -f *.o core a.out


