#include "GameClearScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameClearScene::GameClearScene(GameObject* parent)
    : GameObject(parent, "GameOverScene"), sprite(nullptr)
{
}

void GameClearScene::Initialize()
{
    sprite = new Sprite();
    sprite->Initialize(L"Assets/gameclear.png");
}

void GameClearScene::Update()
{
    if (Input::IsKeyDown(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TITLE);
    }
}

void GameClearScene::Draw()
{
    Transform transform;
    if (sprite) {
        sprite->Draw(transform);
    }
}

void GameClearScene::Release()
{
}
