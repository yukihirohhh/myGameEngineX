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

    transform_.position_.y = 5.0f;
    transform_.scale_.x = 0.5f;
    transform_.scale_.y = 0.5f;
    transform_.scale_.z = 0.5f;
    //SphereCollider* collision = new SphereCollider(1.0f);
    //AddCollider(collision);
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
