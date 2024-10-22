#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//プレイヤーを管理するクラス
class MiniOden : public GameObject
{
    Fbx* pFbx;
public:
    MiniOden(GameObject* parent);
    ~MiniOden();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};