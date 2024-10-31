#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Sprite.h"


TitleScene::TitleScene(GameObject* parent)
    : GameObject(parent, "TitleScene"), sprite(nullptr)
{
}

void TitleScene::Initialize()
{
    sprite = new Sprite();
    sprite->Initialize(L"Assets/title.png");
}

void TitleScene::Update()
{
    if (Input::IsKeyDown(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_PLAY);
    }
}

void TitleScene::Draw()
{
    Transform transform;
    if (sprite) {
        sprite->Draw(transform);
    }
}

void TitleScene::Release()
{
}
