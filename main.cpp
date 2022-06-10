#include <iostream>
#include <graphics.h>
using namespace std;

class Character{
	private:
		static const int SIZE  = 50;
		static const int OUTLINE_COLOR = WHITE;
		static const int FILL_COLOR = YELLOW;

		int x, y;
		int atk, hp;

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
		static const int SIZE  = 7;
		static const int OUTLINE_COLOR = WHITE;
		static const int FILL_COLOR = YELLOW;

		int score;
		int x, y;

		void draw(int outline, int fill) const{
			setcolor(outline);
			setfillstyle(SOLID_FILL, fill);
			fillellipse(x,y, SIZE, SIZE);
		}

	public:
		Lia(int _score = 0, int _x=0, int _y=0){score = _score; x = _x; y = _y;}

	void specialAttack() const;


};

class Enemy : public Character{
	private:
	public:
};

class Karen : public Enemy{
	private:
	public:
	void specialAttack() const;
};

class Trap{
	private:
	int trapAtk;
	public:
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
	char welcome[] = "Welcome to Lia's Quest, press C to continue or escape to quit the game";
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(width/2, height/2, welcome);

	setactivepage(1);
	char page1[] = "Pretend you are playing lol, press P to go to main menu";
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
					if (key == 'A')
						lia.move(-10, 0);
					else if (key == 'D')
						lia.move(10, 0);
					else if (key == 'W')
					    lia.move(0, -10);
					else if (key == 'S')
					    lia.move(0, 10);
				} else {
					key = getch();
					cout << "clicked: " << key;
					if(key == 75)
						lia.move(-10, 0);
					else if(key == 77)
						lia.move(10, 0);
					else if(key == 72)
						lia.move(0, -10);
					else if(key == 80)
						lia.move(0, 10);
				}
			}
		}
	}
	getch();
	return 0;
}