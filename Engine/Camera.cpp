#include "Camera.h"

namespace Camera
{
	XMVECTOR position_;		//�J�����̈ʒu�i���_�j
	XMVECTOR target_;		//����ʒu�i�œ_�j
	XMMATRIX viewMatrix_;	//�r���[�s��
	XMMATRIX projMatrix_;	//�v���W�F�N�V�����s��
};

void Camera::Initialize()
{
	position_ = XMVectorSet(0, 3, -10, 0);
	target_ = XMVectorSet(0, 0, 0, 0);
	projMatrix_ = XMMatrixPerspectiveFovLH(XM_PIDIV4, (FLOAT)800 / (FLOAT)600, 0.1f, 100.0f);
}

void Camera::Update()
{
	viewMatrix_ = XMMatrixLookAtLH(position_, target_, XMVectorSet(0, 1, 0, 0));
}

void Camera::SetPosition(XMVECTOR position)
{
	position_ = position;
}

void Camera::SetTarget(XMVECTOR target)
{
	target_ = target;
}

XMMATRIX Camera::GetViewMatrix()
{
	return viewMatrix_;
}

XMMATRIX Camera::GetProjectionMatrix()
{
	return projMatrix_;
}