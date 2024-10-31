#include "Enemy.h"
#include "Engine/Input.h"
#include "ChildOden.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy")
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.position_.z = 20.0f;


    SphereCollider* collision = new SphereCollider(1.0f);
    AddCollider(collision);
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
    pFbx->Draw(transform_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    KillMe();
    pTarget->KillMe();


}
