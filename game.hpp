#ifndef GAME_H
#define GAME_H


class Character{
	private:
		static const int SIZE_LIA  = 50;
		static const int OUTLINE_COLOR_LIA = WHITE;
		static const int FILL_COLOR_LIA = YELLOW;

		int x, y;
		int vx, vy;
		int ax, ay;
		float g; //to calculate Lia's gravity when jumping
		int atk, hp; //atk for damage strength while hp is for health points

		// a helper method
		void draw(int outline, int fill) const;

	public:
		Character(int _x=0, int _y=0, int _vx=0, int _vy=0, int _ax=0, int _ay=0, int _g=0, int _atk=100, int _hp=50);
		void show() const;
		void clear() const;
		void setPos(int _x=0, int _y=0);
		void move(int dx=0, int dy=0);
		void updateMove();
		void attack();
		void damage();

};

class Lia : public Character{
	private:
		void specialAttack() const;
	public:
	    void Jump() const;
		
};

class CatFood{
	private:
	static const int SIZE_CATFOOD  = 10;
	static const int OUTLINE_COLOR_CATFOOD = WHITE;
	static const int FILL_COLOR_CATFOOD = BLUE;

	int x, y;
	
	void draw(int outline, int fill) const;

	public:
	CatFood(int _x=0, int _y=0);
	void show() const;
	void clear() const;
	void setPos(int _x=0, int _y=0);
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