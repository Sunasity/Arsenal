####CC#####
CXX = g++
CFLAGS = -Wall -g
####path####
vpath %.hpp include
vpath %.cpp src
INC = -I./include
BIN = bin
TARGET = $(BIN)/Arsenal
OBJSDIR = obj
####objs####
OBJS = Mat_computation.o Test.o 

.PHONY : all
all : $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) -fopenmp
	mv $(OBJS) $(OBJSDIR)


%.o : %.cpp 
	$(CXX) $(CFLAGS) $(INC) -o $@ -c $< -fopenmp


.PHONY : clean
clean :
	rm  $(OBJSDIR)/*.o $(BIN)/Arsenal
