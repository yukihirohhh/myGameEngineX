#include "ChildOden.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Enemy.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    hModel_ = Model::Load("Assets/oden.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;

    //SphereCollider* collision = new SphereCollider(1.0f);
    //AddCollider(collision);
}

//更新
void Bullet::Update()
{
    transform_.rotate_.y += 2.0;
    transform_.position_.y += 0.1;
    Enemy* enemy = (Enemy*)FindObject("Enemy");
    float r1 = 0.1;
    float r2 = 0.5;
    XMFLOAT3 P1 = enemy->GetPosition();
    XMFLOAT3 P2 = transform_.position_;
    XMVECTOR Dist = XMVector3Length(
        XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1)
    );
    float d = XMVectorGetX(Dist);
    if (d <= r1 + r2)
    {
        KillMe();
    }

    if (transform_.position_.y > 5.0)
    {
        KillMe();
    }

}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}