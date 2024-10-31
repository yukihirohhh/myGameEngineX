#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

class GameClearScene : public GameObject
{
	Sprite* sprite;
public:
	GameClearScene(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};