#include <iostream>
#include <graphics.h>
#include "game.hpp"
using namespace std;

int main()
{
	int width = 800;
	int height = 600;
	char gamename[] = "Lia's Quest";
	initwindow(width, height, gamename);

	bool playing = false;
	setvisualpage(0);

	setactivepage(0);
	GameMenu menu;
	menu.showMenu();

	setactivepage(1);
	char page1[] = "Pretend you are playing lol, use arrow keys, press P to go to main menu";
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(width/2, height/2, page1);
	Character lia(0, height / 2);
	lia.show();

	Character uncle1(500, height/2); 
	uncle1.setFillColor(BLUE);
	uncle1.show();



	char key = 0;
	while(true) {
		if(kbhit()) {
			key = getch();
			if (key > 0) {
				key = toupper(key);
				if(key == 'C')
				{
					setvisualpage(1);
					playing = true;
				}
				if(key == 'P')
				{
					setvisualpage(0);
					playing = false;
				}
				 if (key == 27)
					break;
			}
			if (playing == true)
			{
				if (key > 0)
				{
					// cout << "Clicked: " << key << endl;
					if (key == 'A')
						lia.move(-10, 0); // key A to go left
					else if (key == 'D')
						lia.move(10, 0); //  Key D to go right
					else if(key == 'B')
					{
						SpecialAttack a(lia.getX(), height / 2, height / 20);
						a.setFillColor(LIGHTBLUE);

						setwritemode(XOR_PUT); // To set the graphical display mode such that, 
						// when you draw an object on the same object, the effect will be, the object will be cleared

						int inc1 = 30; // increment for Circle a
						while (!kbhit())
						{
							a.draw(); // First drawing, will display the circle
							delay(80);
							a.draw(); // Second drawing, will clear the circle as we draw the same thing. This is the effect of the XOR_PUT drawing mode
							a.setX(a.getX() + inc1); // move the circle by incrementing x axis
						}
						setwritemode(COPY_PUT);
						while (true)
						{
							if (a.getX() == uncle1.getX()){
								uncle1.sethp(uncle1.getHP() - 25);
								cout << uncle1.getHP();
							}
						}
					}
						
						
				} else {
					key = getch();
					// cout << "clicked: " << key << endl;
					if(key == 75)
						lia.move(-10, 0); // left arrow key
					else if(key == 77)
						lia.move(10, 0); // right arrow key
				}
			}
			if (key == 27) break; // exit when ESC is pressed
		}

	}
	getch();
	return 0;
}