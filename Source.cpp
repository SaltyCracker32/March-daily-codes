#include <iostream>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class invader {
public:
	void init(int x, int y, int h);
	void draw();
	void print();
private:
	int xpos;
	int ypos;
	int hp;
};

ALLEGRO_BITMAP *INVADER = NULL;
ALLEGRO_DISPLAY *display = NULL;

int main() {

	al_init();
	al_init_image_addon();

	INVADER = al_load_bitmap("invade.jpg");

	display = al_create_display(800, 800);
	al_set_new_window_title("Noodles.jpg");

	invader one;
	invader two;
	invader three;
	invader four;

	one.init(200, 100, 10);
	two.init(400, 100, 10);
	three.init(200, 500, 20);
	four.init(400, 500, 20);

	std::cout << "one: " << std::endl;
	one.print();
	std::cout << "two: " << std::endl;
	two.print();
	std::cout << "three: " << std::endl;
	three.print();
	std::cout << "four: " << std::endl;
	four.print();

	while (true) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		one.draw();
		two.draw();
		three.draw();
		four.draw();
		al_flip_display();
	}

	al_destroy_display(display);

}

void invader::init(int x, int y, int h) {
	xpos = x;
	ypos = y;
	hp = h;
}

void invader::draw() {
	al_draw_scaled_bitmap(INVADER, 0, 0, al_get_bitmap_width(INVADER), al_get_bitmap_height(INVADER), xpos, ypos, 200, 100, 0);
}

void invader::print() {
	std::cout << "xpos: " << xpos << std::endl;
	std::cout << "ypos: " << ypos << std::endl;
	std::cout << "hp: " << hp << std::endl;
}