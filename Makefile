playerandenemies:
	g++ -o playerandenemies main.cpp `pkg-config --cflags --libs ncurses`

clean:
	rm -f playerandenemies

