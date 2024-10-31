#include "Player.h"
#include "Engine/Input.h"
#include "ChildOden.h"
#include "MiniOden.h"
#include "Engine/SceneManager.h"

Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.scale_.x = 0.5f;
    transform_.scale_.y = 0.5f;
    transform_.scale_.z = 0.5f;


}

void Player::Update()
{
    transform_.rotate_.y += 50;

    if (Input::IsKey(DIK_LEFT))
    {
        transform_.position_.x -= 0.2f;
    }
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.position_.x += 0.2f;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        GameObject* pBullet = Instantiate<Bullet>(pParent_);
        pBullet->SetPosition(transform_.position_);

    }

}

void Player::Draw()
{
    pFbx->Draw(transform_);
}

void Player::Release()
{
}