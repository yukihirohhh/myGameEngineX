#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//プレイヤーを管理するクラス
class Bullet : public GameObject
{
    Fbx* pFbx;
    int hModel_;
public:
    Bullet(GameObject* parent);
    ~Bullet();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void OnCollision(GameObject* pTarget);
};