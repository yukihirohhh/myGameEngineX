#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

class TitleScene : public GameObject
{
	Sprite* m_pTitleSprite;
public:
	TitleScene(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};