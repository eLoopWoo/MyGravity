#include "player.h"

void player::set_g(double force) {
	gravity = force;
}
void player::set_size(float s) {
	me.setPointCount(32);
	me.setRadius(s);
	me.rotate(45);
}
void player::set_x(double x) {
	cor_x = x;
	me.setPosition(sf::Vector2f(cor_x, cor_y));
}
void player::set_y(double y) {
	cor_y = y;
	me.setPosition(sf::Vector2f(cor_x, cor_y));
}
void player::set_m(double m) {
	mass = m;
}
void player::set_force_x(double x) {
	force_x = x;
}
void player::set_force_y(double y) {
	force_y= y;
}

double player::get_x() {
	return cor_x;
}
double player::get_y() {
	return cor_y;
}
double player::get_g() {
	return gravity;
}
double player::get_m() {
	return mass;
}
double player::get_force_x() {
	return force_x;
}
double player::get_force_y() {
	return force_y;
}


void player::print() {
	(*window).draw(me);
}


