#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
    Fbx* pFbx;
public:
    Player(GameObject* parent);
    ~Player();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};