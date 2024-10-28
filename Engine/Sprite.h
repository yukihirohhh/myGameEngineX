#pragma once
#include "Direct3D.h"
#include "Texture.h"
#include "Transform.h"

#define SAFE_DELETE_ARRAY(p) if(p != nullptr){ delete[] p; p = nullptr;}

//四角形ポリゴン（三角形を２枚）を描画するクラス
class Sprite
{
	//コンスタントバッファー
struct CONSTANT_BUFFER
{
	XMMATRIX	matW;		//ワールド行列
};

struct VERTEX
{
	XMVECTOR position;	//位置
	XMVECTOR uv;		//UV
};
protected:
	DWORD	vertexNum_;		//頂点数
	VERTEX* vertices_;		//頂点情報
	ID3D11Buffer* pVertexBuffer_;		//頂点バッファ
	DWORD indexNum;			//インデックス数
	int* index_;			//インデックス情報
	ID3D11Buffer* pIndexBuffer_;		//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	Texture* pTexture_;		//テクスチャ
public:
	Sprite();
	~Sprite();
	HRESULT Initialize();
	void Draw(Transform& transform);
	void Release();
private:
	virtual void InitVertexData();		//頂点情報の準備
	HRESULT CreateVertexBuffer();		//頂点バッファを作成
	virtual void InitIndexData();		//インデックス情報を準備
	HRESULT CreateIndexBuffer();		//インデックスバッファを作成
	HRESULT CreateConstantBuffer();		//コンスタントバッファ作成
	HRESULT LoadTexture();				//テクスチャをロード
	void PassDataToCB(DirectX::XMMATRIX worldMatrix);	//コンスタントバッファに各種情報を渡す
	void SetBufferToPipeline();							//各バッファをパイプラインにセット
};