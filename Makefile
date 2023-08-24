playerandenemies:
	g++ -o playerandenemies main.cpp `pkg-config --cflags --libs ncurses` -lm

clean:
	rm -f playerandenemies

