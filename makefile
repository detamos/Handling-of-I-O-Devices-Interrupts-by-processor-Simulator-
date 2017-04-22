
CC = g++
CFLAGS = -g -I

RM = rm 
RMFLAGS = -r -f

LIBS = -lm

SRCS_PQ  = ./src/pQueue.cpp
SRCS 	 = ./src/simulator.cpp

INCLUDES = ./include/

all:   clean pQueue simulator

clean:	
	$(RM) $(RMFLAGS) ./bin/*
pQueue:	$(SRCS_pQ)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_PQ) -o ./bin/pQueue $(LIBS)
simulator:	$(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o ./bin/simulator $(LIBS)
