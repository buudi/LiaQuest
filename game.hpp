#ifndef GAME_H
#define GAME_H


class SpecialAttack {

	private:
		int x, y, r;
		int colorOutline;
		int colorFill;
	public:
		SpecialAttack(int _x = 0, int _y = 0, int _r = 0, int _colorOutline = COLOR(255, 255, 255), int _colorFill = 0);
		void setX(int _x);
		void setY(int _y);
		void setCenter(int _x, int _y);
		void setR(int _r);
		void setOutlineColor(int _colorOutline);
		void setFillColor(int _colorFill);
		void setColor(int _colorOutline, int _colorFill);

		// Accessors
		int getX();
		int getY();
		int getR();
		int getOutlineColor();
		int getFillColor();
		void draw();
};

class Character{
	private:
		static const int SIZE  = 50;
		static const int OUTLINE_COLOR = WHITE;
		
		int FILL_COLOR = YELLOW;

		int x, y;
		int atk; //atk for damage strength while hp is for health points
		int hp = 100;

		// a helper method
		void draw(int outline, int fill) const;

	public:
		Character(int _x=0, int _y=0, int _FILL_COLOR=YELLOW, int _atk=100, int _hp=50);
		void show() const;
		void clear() const;
		void setPos(int _x=0, int _y=0);
		void move(int dx=0, int dy=0);
		void attack();
		void damage();
		int getX();
		int getHP();
		void setFillColor(int _FILL_COLOR) ;
		void sethp(int _hp);

};



class Lia : public Character{
	private:
		Character *lia;
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
		void textstyle();
		void title();
		void buttons();
	public:
		void showMenu();
};

#endif