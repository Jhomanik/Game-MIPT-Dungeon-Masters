#pragma once
#include"Button.h"


class Menu
{
public:
	Menu(float width, float height, std::vector <Button*>& buttons);
	void SetSprite(std::string& src);
	void SetTitle(std::string& title_str);
	int GetPressedItem() { return selectedItemIndex; } 

	void MoveUp();                            
	void MoveDown();

	void draw(sf::RenderWindow& window);
	void input();


protected:
	std::vector <Button*> menu;
	int MAX_NUMBER_OF_ITEMS;
	bool is_first_pressed = false;
	sf::Text title;
	int selectedItemIndex;
	sf::Font font;
	sf::Texture texture;
	sf::Sprite sprite;
	float menu_width, menu_height;
	std::string src_image;
	std::string title_source;
	
};

class MainMenu :public Menu {
public:
	MainMenu(float width, float height, std::vector <Button*>& buttons):Menu( width, height, buttons){}
	void update(bool& is_menu,bool& go_to_choice, bool& is_over)
	{
		menu[0]->update(is_menu);
		menu[1]->update(go_to_choice);
		menu[2]->update(is_over);
		if (is_first_pressed) {
			menu[0]->SelectButton();
			is_first_pressed = false;
		}
	}
	
};

class MissionMenu :public Menu {
public:
	MissionMenu(float width, float height, std::vector <Button*>& buttons) :Menu(width, height, buttons) {}
	void update(bool& is_menu,bool& is_restart, bool& is_mission)
	{
		menu[0]->update(is_menu);
		menu[1]->update(is_restart);
		menu[2]->update(is_mission);

		if (is_first_pressed) {
			menu[0]->SelectButton();
			is_first_pressed = false;
		}

	}

	MissionMenu* copy() {
		std::vector <Button*> new_buttons;
		for (auto b : menu) {
			new_buttons.push_back(b->copy());
		}
		MissionMenu* m = new MissionMenu(menu_width, menu_height, new_buttons);
		m->SetSprite(src_image);
		m->SetTitle(title_source);
		return m;
	}

};

class ChoiceMenu :public Menu {
public:
	sf::Color default_color = sf::Color::White;
	sf::Color hold_color = sf::Color::Green;
	int hold_num = 0;
	ChoiceMenu(float width, float height, std::vector<Button* > b):Menu(width, height,b) {
		menu[0]->SetUnselelectedColor(hold_color);
		
	}
	void MarkButton(int ind, bool is_done) {		
		menu[ind]->MarkButton(is_done);
	}
	void update(bool& is_exit, int& num) {
		
		for (int i = 0;i < menu.size();i++) {
			if (i != menu.size() - 1) {
				bool choose = false;
				menu[i]->update(choose);
				if (choose) {
					menu[hold_num]->SetUnselelectedColor(default_color);
					hold_num = i;
					num = i;
					menu[i]->SetUnselelectedColor(hold_color);	
				}
			}
			else {
				menu[i]->update(is_exit);
			}
		}
	}
};
