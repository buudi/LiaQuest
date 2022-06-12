#ifndef GAME_H
#define GAME_H

class Character{
	private:
		static const int SIZE  = 50;
		static const int OUTLINE_COLOR = WHITE;
		static const int FILL_COLOR = YELLOW;

		int x, y;
		int atk, hp; //atk for damage strength while hp is for health points

		// a helper method
		void draw(int outline, int fill) const;

	public:
		Character(int _x=0, int _y=0, int _atk=100, int _hp=50);
		void show() const;
		void clear() const;
		void setPos(int _x=0, int _y=0);
		void move(int dx=0, int dy=0);
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
		void textstyle();
		void title();
		void buttons();
	public:
		void showMenu();
};

#endif