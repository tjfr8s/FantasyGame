
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

DiceTest: Dice.o DiceTest.o
	$(CXX) $^ -o DiceTest 

CharacterTest: Character.o CharacterTest.o Battle.o Vampire.o Dice.o
	$(CXX) $^ -o CharacterTest 

VampireTest: Character.o VampireTest.o Battle.o Vampire.o Dice.o
	$(CXX) $^ -o VampireTest 


#AnimalTest: Animal.o AnimalTest.o
#	$(CXX) $^ -o AnimalTest
#


$(OBJS): $(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.$(SRCEXT))


#AnimalTest.o: ./test/AnimalTest.cpp
#	$(CXX) $(CXXFLAGS) -c ./test/AnimalTest.cpp
#


.PHONY: clean
clean:
	rm *.o BattleGame CharacterTest VampireTest

	

