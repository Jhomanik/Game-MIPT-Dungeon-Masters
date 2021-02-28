#pragma once
#include <SFML/Graphics.hpp>
//Ѕазовые классы дл€ свойств рисовки и обновлени€
class drawable {
protected:
	void virtual draw() {};
};

class updatable {
protected:
	void virtual update() {};
};
