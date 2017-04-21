
CC = g++
CFLAGS = -g -I

RM = rm 
RMFLAGS = -r -f

LIBS = -lm

SRCS_PQ  = ./src/pQueue.cpp

INCLUDES = ./include/

all:   clean pQueue

clean:	
	$(RM) $(RMFLAGS) ./bin/*
pQueue:	$(SRCS_pQ)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_PQ) -o ./bin/pQueue $(LIBS)
