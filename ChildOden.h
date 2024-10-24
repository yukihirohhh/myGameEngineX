#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"

//�v���C���[���Ǘ�����N���X
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