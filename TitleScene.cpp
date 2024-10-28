#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Sprite.h"


TitleScene::TitleScene(GameObject* parent)
    : GameObject(parent, "TitleScene"), m_pTitleSprite(nullptr)
{
}

void TitleScene::Initialize()
{
    m_pTitleSprite = new Sprite();
    m_pTitleSprite->Initialize();
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
    if (m_pTitleSprite) {
        m_pTitleSprite->Draw(transform);
    }
}

void TitleScene::Release()
{
}
