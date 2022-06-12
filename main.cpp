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



	char key = 0;
	while(key != 27) {
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
					cout << "Clicked: " << key << endl;
					if (key == 'A')
						lia.move(-10, 0);
					else if (key == 'D')
						lia.move(10, 0);
				} else {
					key = getch();
					cout << "clicked: " << key << endl;
					if(key == 75)
						lia.move(-10, 0);
					else if(key == 77)
						lia.move(10, 0);
				}
			}
		}
	}
	getch();
	return 0;
}