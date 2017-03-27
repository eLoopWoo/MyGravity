#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <player.h>

player* player1;





sf::CircleShape mk_triangle(sf::RenderWindow& window,int w,int z){
	sf::CircleShape triangle(40, 3);
	triangle.setPosition(sf::Vector2f(w, z));
	triangle.setFillColor(sf::Color(60, 255, 255));
	return triangle;
}



void move(int direction,player* player) {
		switch (direction) {
		case (1):
			//if((*player).get_x() < 600)
				(*player).set_force_x((*player).get_force_x() + 1);
			return;
		case (2):
			//if ((*player).get_x() > 40)
				(*player).set_force_x((*player).get_force_x() - 1);

			return;
		case(3):
			//if((*player).get_y() < 400)
				(*player).set_force_y((*player).get_force_y() + 1);
			return;
		case(4):
			//if ((*player).get_y() > 10)
				(*player).set_force_y((*player).get_force_y() - 1);
				//(*player).set_y((*player).get_y() - 10);
			return;
			}
	return;
}


void gravity_control(player* player) {
	//
	double a_y;
	double a_x;



	//if ((*player).get_force_x() > 0)
	//	(*player).set_force_x((*player).get_force_x() - 0.001);
	//if ((*player).get_force_x() < 0)
	//	(*player).set_force_x((*player).get_force_x() + 0.001);




	(*player).set_force_y((*player).get_force_y() + (*player).get_g()); // f = g + force
	a_y = ((((*player).get_force_y()) / (*player).get_m())); // a = ( f / m )
	(*player).set_y((*player).get_y() + a_y);

	a_x = (*player).get_force_x();
	(*player).set_x((*player).get_x() + a_x);

	if (!((*player).get_x() < 600)) {
		(*player).set_x(600);
		(*player).set_force_x(-1 * (*player1).get_force_x());

	}
	if (!((*player).get_x() > 40)) {
		(*player).set_x(40);
		(*player).set_force_x(-1 * (*player1).get_force_x());

	}
	if (!((*player).get_y() < 400)) {
		(*player).set_y(400);
		(*player).set_force_y(-0.5 * (*player1).get_force_y());


	}
	if (!((*player).get_y() > 10)) {
		(*player).set_y(10);
		(*player).set_force_y(-1 * (*player1).get_force_y());

	}


}


void test(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime) {
	gravity_control(player1);
	return;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	
	player1 = new player;
	(*player1).window = &window;

	(*player1).set_x(100);
	(*player1).set_y(150);
	(*player1).set_size(30);
	(*player1).set_g(0.05);
	(*player1).set_m(1);
	UINT_PTR timerid = SetTimer(NULL, 0, 10, (TIMERPROC) &test);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128) {
					switch (event.text.unicode) {
					case 'd':
						printf("%c", event.text.unicode);
						move(1, player1);
						break;
					case 'a':
						printf("%c", event.text.unicode);
						move(2, player1);
						break;
					case 's':
						printf("%c", event.text.unicode);
						move(3, player1);
						break;
					case 'w':
						printf("%c", event.text.unicode);
						move(4, player1);
						break;
					default:
						break;
					}
					break;
				}
				break;
			}
		}



		window.clear();
		(*player1).print();
		window.display();
	}
}