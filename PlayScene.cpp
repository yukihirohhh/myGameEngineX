#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	
}

void PlayScene::Update()
{
	GameObject* test = FindObject("SceneManager");
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
