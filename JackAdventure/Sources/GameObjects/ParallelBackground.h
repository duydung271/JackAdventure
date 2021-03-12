#pragma once
#include "Layer.h"

class ParallexBackground
{
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<Layer*> m_Background;
};