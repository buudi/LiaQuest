#include <iostream>
#include <string>
#include <graphics.h>
#include "game.hpp"
using namespace std;


//----------------------------------------------------------
// Special Attack Class

SpecialAttack::SpecialAttack(int _x, int _y, int _r, int _colorOutline , int _colorFill)
{
	x = _x;
	y = _y;
	r = _r;
	colorOutline = _colorOutline;
	colorFill = _colorFill;
}

void SpecialAttack::setX(int _x) { x = _x; }
void SpecialAttack::setY(int _y) { y = _y; }
void SpecialAttack::setCenter(int _x, int _y) { x = _x; y = _y; }
void SpecialAttack::setR(int _r) { r = _r; }
void SpecialAttack::setOutlineColor(int _colorOutline) { colorOutline = _colorOutline; }
void SpecialAttack::setFillColor(int _colorFill) { colorFill = _colorFill; }
void SpecialAttack::setColor(int _colorOutline, int _colorFill) { colorOutline = _colorOutline, colorFill = _colorFill; }


int SpecialAttack::getX()  { return x; }
int SpecialAttack::getY()  { return y; }
int SpecialAttack::getR()  { return r; }
int SpecialAttack::getOutlineColor()  { return colorOutline; }
int SpecialAttack::getFillColor()  { return colorFill; }

void SpecialAttack::draw() 
{
	setcolor(colorOutline);
	setfillstyle(SOLID_FILL, colorFill);
	fillellipse(x, y, r, r);
}


// Character Class
void Character::draw (int outline, int fill) const{
    setcolor(outline);
	setfillstyle(SOLID_FILL, fill);
	fillellipse(x,y, SIZE, SIZE);
}

Character::Character(int _x, int _y, int _atk, int _hp, int _FILL_COLOR){
	x = _x; y=_y; atk = _atk; hp = _hp;
}

void Character::show() const{
    draw(OUTLINE_COLOR, FILL_COLOR); 
}

void Character::clear() const{
    draw(BLACK, BLACK);
}

void Character::setPos(int _x, int _y){
    x = _x; 
    y=_y;
}

void Character::move(int dx, int dy){
    clear();
	x += dx;
    y += dy;
	show();
}
int Character::getX(){
	return x;
}
int Character::getHP(){
	return hp;
}

void Character::setFillColor(int _FILL_COLOR=YELLOW) 
{
	FILL_COLOR = _FILL_COLOR;
}

void Character::sethp(int _hp)
{
	hp = _hp;
}


void Character::attack(){

}

void Character::damage(){

}
//----------------------------------------------------------
// Lia Class

void Lia::specialAttack() const{
	lia->attack();
}
//----------------------------------------------------------
// Enemy CLass

//----------------------------------------------------------
// Karen Class

void Karen::specialAttack() const{
    
}
//----------------------------------------------------------
//Trap Class

//----------------------------------------------------------
//Game Menu Class

void GameMenu::textstyle(){
    settextjustify(DIRECTION, DIRECTION);
	settextstyle(FONT, HORIZ_DIR, 3);
}

void GameMenu::title(){
    char mainMsg[] = "Lia's Quest";
	textstyle();
	outtextxy(400, 200, mainMsg);
}

void GameMenu::buttons(){
    textstyle();
	char startMsg[] = "Play (press C)";
	outtextxy(395,330, startMsg);
	rectangle(250, 300, 550, 350);

	char exitMsg[] = "Quit (press ESC twice)";
	outtextxy(395,410, exitMsg);
	rectangle(250, 380, 550, 430);
}

void GameMenu::showMenu(){
    title();
	buttons();
}
