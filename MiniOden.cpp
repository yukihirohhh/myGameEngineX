#include "MiniOden.h"

MiniOden::MiniOden(GameObject* parent)
    :GameObject(parent, "MiniOden")
{
}

MiniOden::~MiniOden()
{
}

void MiniOden::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/oden.fbx");

    transform_.position_.x = 2.0f;

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
}

void MiniOden::Update()
{
  
}

void MiniOden::Draw()
{
    pFbx->Draw(transform_);
}

void MiniOden::Release()
{
}