#include "GameOverScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
    : GameObject(parent, "GameOverScene"), sprite(nullptr)
{
}

void GameOverScene::Initialize()
{
    sprite = new Sprite();
    sprite->Initialize(L"Assets/gameover.png");
}

void GameOverScene::Update()
{
    if (Input::IsKeyDown(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TITLE);
    }
}

void GameOverScene::Draw()
{
    Transform transform;
    if (sprite) {
        sprite->Draw(transform);
    }
}

void GameOverScene::Release()
{
}
