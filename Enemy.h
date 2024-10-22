#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//プレイヤーを管理するクラス
class Enemy : 
    public GameObject
{
    Fbx* pFbx;
    int hModel;
public:
    Enemy(GameObject* parent);
    ~Enemy();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    XMFLOAT3 GetPosition() { return (transform_.position_); }
    void OnCollision(GameObject* pTarget) override;
};