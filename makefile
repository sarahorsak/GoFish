final: go_fish.o card.o deck.o player.o
	g++ -o GoFish go_fish.o card.o deck.o player.o
go_fish.o: go_fish.cpp card.h deck.h player.h
	g++ -c go_fish.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
