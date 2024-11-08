//インクルード
#include <Windows.h>
#include <stdlib.h>
#include "Engine/Direct3D.h"
#include "Engine/Camera.h"
#include "Engine/Transform.h"
#include "Engine/Input.h"
#include "Engine/RootJob.h"
#include "Engine/Model.h"

#pragma comment(lib, "winmm.lib")

//定数宣言
LPCWSTR WIN_CLASS_NAME =	L"SampleGame";  //ウィンドウクラス名
const int WINDOW_WIDTH =	800;			//ウィンドウの幅
const int WINDOW_HEIGHT =	600;			//ウィンドウの高さ

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

RootJob* pRootJob;

//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウクラス（設計図）を作成
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);             //この構造体のサイズ
	wc.hInstance = hInstance;                   //インスタンスハンドル
	wc.lpszClassName = WIN_CLASS_NAME;            //ウィンドウクラス名
	wc.lpfnWndProc = WndProc;                   //ウィンドウプロシージャ
	wc.style = CS_VREDRAW | CS_HREDRAW;         //スタイル（デフォルト）
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //小さいアイコン
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);   //マウスカーソル
	wc.lpszMenuName = NULL;                     //メニュー（なし）
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景（白）
	RegisterClassEx(&wc); //クラスを登録

	//ウィンドウサイズの計算
	RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
	int winW = winRect.right - winRect.left;     //ウィンドウ幅
	int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ

	//ウィンドウを作成
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,     //ウィンドウクラス名
		L"サンプルゲーム",  //タイトルバーに表示する内容
		WS_OVERLAPPEDWINDOW,//スタイル（普通のウィンドウ）
		CW_USEDEFAULT,      //表示位置左（おまかせ）
		CW_USEDEFAULT,      //表示位置上（おまかせ）
		winW,				//ウィンドウ幅
		winH,				//ウィンドウ高さ
		NULL,				//親ウインドウ（なし）
		NULL,               //メニュー（なし）
		hInstance,          //インスタンス
		NULL                //パラメータ（なし）
	);

	//ウィンドウを表示
	ShowWindow(hWnd, nCmdShow);

	//COMの初期化
	CoInitialize(nullptr);


	HRESULT hr;
	hr = Direct3D::Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, hWnd);
	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}

	Input::Initialize(hWnd);
	Camera::Initialize();
	pRootJob = new RootJob(nullptr);
	pRootJob->Initialize();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		//メッセージあり
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//メッセージなし
		else
		{
			timeBeginPeriod(1);

			static DWORD countFps = 0;
			static DWORD startTime = timeGetTime();
			DWORD nowTime = timeGetTime();
			static DWORD lastUpdateTime = nowTime;

			if (nowTime - startTime >= 1000)
			{
				WCHAR str[16];
				wsprintf(str, L"%u", countFps);
				SetWindowText(hWnd, str);

				countFps = 0;
				startTime = nowTime;
			}

			if ((nowTime - lastUpdateTime) * 60 <= 1000.0f)
			{
				continue;
			}
			lastUpdateTime = nowTime;
			countFps++;
			Input::Update();
			pRootJob->UpdateSub();
			if (Input::IsKeyUp(DIK_ESCAPE))
			{
				static int cnt = 0;
				cnt++;
				if (cnt >= 3)
				{
					PostQuitMessage(0);
				}
			}
			Direct3D::BeginDraw();
			Camera::Update();
			pRootJob->DrawSub();
			Direct3D::EndDraw();
			timeEndPeriod(1);
		}
	}
	Model::Release();
	pRootJob->ReleaseSub();
	SAFE_DELETE(pRootJob);
	Input::Release();
	Direct3D::Release();
	CoUninitialize();
	return 0;
}

//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);  //プログラム終了
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}