//Include
#include <ctime>
#include <iostream>
#include "map.h"

//Main
int main() {

	//Setup
	system("title Catan++");
	system("mode 115,49");
	srand(time(NULL));

	//Variables
	Renderer renderer;
	Map map;

	//Draw
	renderer.cls();
	map.render(renderer);
	renderer.swapBuffer();

	//End
	system("pause");
	return 0;

}