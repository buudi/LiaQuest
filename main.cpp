#include <iostream>
#include <graphics.h>
using namespace std;

class Character{
	private:
		static const int SIZE  = 50;
		static const int OUTLINE_COLOR = WHITE;
		static const int FILL_COLOR = YELLOW;

		int x, y;
		int atk, hp; //atk for damage strength while hp is for health points

		// a helper method
		void draw(int outline, int fill) const{
			setcolor(outline);
			setfillstyle(SOLID_FILL, fill);
			fillellipse(x,y, SIZE, SIZE);
		}

	public:
		Character(int _x=0, int _y=0, int _atk=100, int _hp=50){
			x = _x; y=_y; atk = _atk; hp = _hp;
		}

	void show() const{draw(OUTLINE_COLOR, FILL_COLOR); }
	void clear() const{draw(BLACK, BLACK); }

	void setPos(int _x=0, int _y=0){ x = _x; y=_y;}

	void move(int dx=0, int dy=0){
		clear();
		x += dx; y += dy;
		show();
	}

	void attack();

	void damage();

};

class Lia : public Character{
	private:
		int score;

	void specialAttack() const;
		
};

class Enemy : public Character{
};

class Karen : public Enemy{
	public:
	void specialAttack() const;
};

class Trap{
	public:
		int strength; //damage strength that trap can inflict
};

class GameMenu{
	private:
		static const int DIRECTION = CENTER_TEXT;
		static const int FONT = SANS_SERIF_FONT;

		// helper methods:
		void textstyle(){
			settextjustify(DIRECTION, DIRECTION);
			settextstyle(FONT, HORIZ_DIR, 3);
		}
		void title(){
			char mainMsg[] = "Lia's Quest";
			textstyle();
			outtextxy(400, 200, mainMsg);
		}
		void buttons(){
			textstyle();
			char startMsg[] = "Play (press C)";
			outtextxy(395,330, startMsg);
			rectangle(250, 300, 550, 350);

			char exitMsg[] = "Quit (press ESC twice)";
			outtextxy(395,410, exitMsg);
			rectangle(250, 380, 550, 430);
		}
	public:
		void showMenu(){
			title();
			buttons();
		}
};

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