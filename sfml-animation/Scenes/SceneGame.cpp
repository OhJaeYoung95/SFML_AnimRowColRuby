#include "stdafx.h"
#include "SceneGame.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "GameObject.h"
#include "Player.h"
#include "Framework.h"

SceneGame::SceneGame() : Scene(SceneId::Game)
{
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/RubySheet.png"));
}

void SceneGame::Init()
{
	Release();

	player = (Player*)AddGo(new Player());
	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneGame::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void SceneGame::Enter()
{
	auto size = FRAMEWORK.GetWindowSize();
	worldView.setSize(size);
	worldView.setCenter(0, 0);

	Scene::Enter();
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);	
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
