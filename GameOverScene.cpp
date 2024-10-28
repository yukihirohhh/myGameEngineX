#include "GameOverScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
    : GameObject(parent, "GameOverScene")
{
}

void GameOverScene::Initialize()
{

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
}

void GameOverScene::Release()
{
}
