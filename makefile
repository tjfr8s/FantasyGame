
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = 

SRCEXT = cpp
INCEXT = hpp

SRCS = $(shell find . -maxdepth 1 -type f -name \*.$(SRCEXT))
OBJS = $(patsubst ./%, ./%, $(SRCS:.$(SRCEXT)=.o))
INCS = $(shell find . -maxdepth 1 -type f -name \*.$(INCEXT))

BattleGame: $(OBJS)
	$(CXX) $^ -o BattleGame

DiceTest: $(OBJS)
	$(CXX) $^ -o DiceTest 


#AnimalTest: Animal.o AnimalTest.o
#	$(CXX) $^ -o AnimalTest
#


$(OBJS): $(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.$(SRCEXT))

DiceTest.o: DiceTest.cpp
	$(CXX) $(CXXFLAGS) -c DiceTest.cpp

#AnimalTest.o: ./test/AnimalTest.cpp
#	$(CXX) $(CXXFLAGS) -c ./test/AnimalTest.cpp
#


.PHONY: clean
clean:
	rm *.o BattleGame

	
