#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//������� ������ ��� ������� ������� � ����������
class drawable {
protected:
	void virtual draw() {};
};

class updatable {
protected:
	void virtual update() {};
};
