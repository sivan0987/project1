CC=gcc
AR=ar
FLAGS= -Wall -g

all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec 
recursives:
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs  libclassrec.a advancedClassificationRecursion.o basicClassification.o
loops:
libclassloops.a: advancedClassificationLoop.o basicClassification.o
	ar -rcs libclassloops.a libclassloops.a advancedClassificationLoop.o basicClassification.o
recursived:
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc  -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
loopd:
libclassloops.so:basicClassification.o advancedClassificationLoop.o
	gcc  -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -c advancedClassificationLoop.c
basicClassification.o: basicClassification.c NumClass.h
	gcc -c basicClassification.c 
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -c advancedClassificationRecursion.c


mains:main.o libclassrec.a
	gcc $(FLAGS) -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so
	gcc $(FLAGS) -o maindloop main.o ./libclassloops.a -lm
maindrec:main.o libclassrec.so 
	gcc $(FLAGS) -o maindrec main.o ./libclassrec.a -lm
main.o: main.c NumClass.h
	gcc $(FLAGS) -c main.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec