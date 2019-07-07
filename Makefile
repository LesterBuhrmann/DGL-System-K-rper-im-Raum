Koerper: main.o Vektor.o
    g++ main.o Vektor.o -o Koerper

main.o: main.cpp
    g++ -c main.cpp

Vektor.o: Vektor.cpp Vektor.h
     g++ -c Vektor.cpp
     
clean:
    rm ∗.o Koerper
