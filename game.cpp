#include <iostream>
#include <string>
#include <graphics.h>
#include "game.hpp"
using namespace std;

// Character Class
void Character::draw (int outline, int fill) const{
    setcolor(outline);
	setfillstyle(SOLID_FILL, fill);
	fillellipse(x,y, SIZE_LIA, SIZE_LIA);
}

Character::Character(int _x, int _y, int _vx, int _vy, int _ax, int _ay, int _g, int _atk, int _hp){
	x = _x; y =_y; vx = _vx; vy = _vy; ax = _ax; ay = _ay; g = _g; atk = _atk; hp = _hp;
}

void Character::show() const{
    draw(OUTLINE_COLOR_LIA, FILL_COLOR_LIA); 
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

void Character::updateMove() {

    if(y < 500)
        vx += g;
    else if(y > 500)             
        y = 500;

    vx += ax;
    vy += ay;

    x += vx;
    y += vy;
}

void Character::attack(){

}

void Character::damage(){

}
//----------------------------------------------------------
// Lia Class

void Lia::specialAttack() const{

}

//----------------------------------------------------------
//CatFood Class

CatFood::CatFood(int _x, int _y){
    x = _x; y =_y;
}

void CatFood::draw (int outline, int fill) const{
    setcolor(outline);
	setfillstyle(SOLID_FILL, fill);
	fillellipse(x,y, SIZE_CATFOOD, SIZE_CATFOOD);
}

void CatFood::show() const{
    draw(OUTLINE_COLOR_CATFOOD, FILL_COLOR_CATFOOD); 
}

void CatFood::clear() const{
    draw(BLACK, BLACK);
}

void CatFood::setPos(int _x, int _y){
    x = _x; 
    y=_y;
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
