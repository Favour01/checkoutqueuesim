###########################################################################
##                  Makefile for HW3 (Grocery Sim)                    ##
###########################################################################
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra
LDFLAGS  = -g3

grocerySim: CheckoutQueue.o  GrocerySim.o main.o 
	${CXX} ${LDFLAGS} -o grocerySim CheckoutQueue.o \
						GrocerySim.o main.o

CheckoutQueue.o: CheckoutQueue.cpp CheckoutQueue.h shopper.h
GrocerySim.o:     GrocerySim.cpp GrocerySim.h CheckoutQueue.h
main.o: GrocerySim.h

clean:
	rm -rf grocerySim *.o *.dSYM

provide:
	provide comp15 hw3 CheckoutQueue.h CheckoutQueue.cpp \
                           shopper.h main.cpp GrocerySim.cpp\
                           	GrocerySim.h Makefile README\
                           	testCheckoutQueue.cpp

