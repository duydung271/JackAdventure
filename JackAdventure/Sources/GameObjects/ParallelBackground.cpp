#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	Layer* layer;
	std::string path = "Background layers/";
	//Layer 2
	layer = new Layer();
	layer->Init(path+"Layer_0009_2",50);
	m_Background.push_back(layer);
	//Layer 3
	layer = new Layer();
	layer->Init(path + "Layer_0008_3", 60);
	m_Background.push_back(layer);
	//Layer 4
	layer = new Layer();
	layer->Init(path + "Layer_0007_Lights", 100);
	m_Background.push_back(layer);
	//Layer 5
	layer = new Layer();
	layer->Init(path + "Layer_0006_4", 110);
	m_Background.push_back(layer);
	//Layer 6
	layer = new Layer();
	layer->Init(path + "Layer_0005_5", 120);
	m_Background.push_back(layer);
	//Layer 7
	layer = new Layer();
	layer->Init(path + "Layer_0004_Lights", 140);
	m_Background.push_back(layer);
	//Layer 8
	layer = new Layer();
	layer->Init(path + "Layer_0003_6", 170);
	m_Background.push_back(layer);
	//Layer 9
	layer = new Layer();
	layer->Init(path + "Layer_0002_7", 200);
	m_Background.push_back(layer);
	//Layer 10
	layer = new Layer();
	layer->Init(path + "Layer_0001_8", 200);
	m_Background.push_back(layer);
	//Layer 1
	layer = new Layer();
	layer->Init(path + "Layer_0000_9", 200);
	m_Background.push_back(layer);
}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}
