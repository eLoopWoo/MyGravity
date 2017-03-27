#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h> 

class player
{
private:
	double cor_x;
	double cor_y;
public:
		sf::CircleShape me;
		sf::RenderWindow* window;
		int size;
		double gravity;

		double mass;

		double force_x;
		double force_y;

		//funcs
		void print();
		void set_size(float s);
		
		//Getters and Setters
		void set_x(double x);
		void set_y(double y);
		void set_m(double m);

		void set_force_x(double x);
		void set_force_y(double y);


		double get_x();
		double get_y();
		double get_m();

		double get_force_x();
		double get_force_y();




		double get_g();
		void set_g(double force);
};
