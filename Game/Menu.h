#pragma once
#include"Button.h"



class Menu
{
public:
	Menu(float width, float height, std::vector <Button*>& buttons);
	void SetSprite(std::string& src);
	sf::Text title;
	void draw(sf::RenderWindow& window);   //Îòðèñîâêà ìåíþ
	void MoveUp();                              //Îòâå÷àåò çà ñìåíó êíîïêè ïðè íàæàòèè ââåðõ  
	void MoveDown();     
	void input();//Àíàëîãè÷íî äëÿ íèçà
	int getPressedItem() { return selectedItemIndex; } //Âñïîìîãàòåëüíàÿ ôóíöèÿ äëÿ ñ÷åò÷èêà êíîïîê
	void SetTitle(std::string& title_str);

protected:
	std::vector <Button*> menu;
	int MAX_NUMBER_OF_ITEMS;
	bool is_first_pressed = false;
private:

	int selectedItemIndex;
	sf::Font font;
	sf::Texture texture;
	sf::Sprite sprite;
	float menu_width, menu_height;
	
};

class MainMenu :public Menu {
public:
	MainMenu(float width, float height, std::vector <Button*>& buttons):Menu( width, height, buttons){}
	void update(bool& is_menu, bool& is_over)
	{
		menu[0]->update(is_menu);
		menu[1]->update(is_over);
		if (is_first_pressed) {
			menu[0]->SelectButton();
			is_first_pressed = false;
		}
	}
};

class MissionMenu :public Menu {
public:
	MissionMenu(float width, float height, std::vector <Button*>& buttons) :Menu(width, height, buttons) {}
	void update(bool& is_menu, bool& is_mission)
	{
		menu[0]->update(is_menu);
		menu[1]->update(is_mission);
		if (is_first_pressed) {
			menu[0]->SelectButton();
			is_first_pressed = false;
		}

	}

};

