#pragma once
#include <SFML/Graphics.hpp>
//������� ������ ��� ������� ������� � ����������
class drawable {
protected:
	void virtual draw() {};
};

class updatable {
protected:
	void virtual update() {};
};
