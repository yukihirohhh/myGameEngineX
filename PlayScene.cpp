#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
    Instantiate<Player>(this);
    Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
    if (FindObject("Enemy") == nullptr)
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        if (pSceneManager != nullptr)
        {
            pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
        }
    }

    if (Input::IsKeyDown(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        if (pSceneManager != nullptr)
        {
            pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
        }
    }
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
