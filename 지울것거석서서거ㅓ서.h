#pragma once

//// ======================추가된것==========================

//image.h에 추가된것
//BLENDFUNCTION		_blendFunc;		//알파블렌드 관련 함수를 포함
//LPIMAGE_INFO		_blendImage;	//알파처리할 이미지
//
//void alphaRender(HDC hdc, BYTE alpha);
//void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
//
//
//
//image.cpp    init에 추가된것
////알파블렌드 설정함.
//	//진형 + 치영이는 집중해서 봐라
//	_blendFunc.BlendFlags = 0;
//_blendFunc.AlphaFormat = 0;
//_blendFunc.BlendOp = AC_SRC_OVER;	//<-- 이건 한 번 조사해보세요 여러분					SRC = 변수이름
//
//_blendImage = new IMAGE_INFO;
//_blendImage->loadType = LOAD_EMPTY;
//_blendImage->resID = 0;
//_blendImage->hMemDC = CreateCompatibleDC(hdc);
//_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
//_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
//_blendImage->width = WINSIZEX;
//_blendImage->height = WINSIZEY;
//
//
//
//image.cpp   release에 추가된것
////각 init함수에 알파블렌드 처리할 이미지도 할당되고 있기 때문에
//		//같이 해제해줘야합니다!!!!!!!!!!!!!!!
//	SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
//DeleteObject(_blendImage->hBit);
//DeleteDC(_blendImage->hMemDC);
//
//
//void image::alphaRender(HDC hdc, BYTE alpha)
//{
//	//순서에 주의합시다
//	//BYTE는 알파블렌드 수치값이다. 0 ~ 255의 범위를 가진다
//	//값이 작을수록 투명도가 높다
//
//	//이것을 해야 알파값이 적용됨!!!
//	_blendFunc.SourceConstantAlpha = alpha;
//
//	if (_trans)
//	{
//		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
//			hdc, 0, 0, SRCCOPY);
//
//		//특정칼라를 제외하고 DC -> DC 사이로 고속복사 해주는 함수
//		GdiTransparentBlt(
//			_blendImage->hMemDC,	//복사될 DC
//			0,						//이미지 그려줄 시작X좌표(left)
//			0,						//이미지 그려줄 시작Y좌표(top)
//			_imageInfo->width,		//복사될 가로크기
//			_imageInfo->height,		//복사될 세로크기
//			_imageInfo->hMemDC,
//			0, 0,					//복사시작할 XY좌표
//			_imageInfo->width,		//복사할 가로/세로크기
//			_imageInfo->height,
//			_transColor				//복사때 제외할 칼라(뺄 칼라)
//		);
//
//		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width,
//			_imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
//			_blendFunc);
//	}
//	else
//	{
//		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width,
//			_imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
//			_blendFunc);
//	}
//}
//
//void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
//{
//	//순서에 주의합시다
//	//BYTE는 알파블렌드 수치값이다. 0 ~ 255의 범위를 가진다
//	//값이 작을수록 투명도가 높다
//
//	//이것을 해야 알파값이 적용됨!!!
//	_blendFunc.SourceConstantAlpha = alpha;
//
//	if (_trans)
//	{
//		BitBlt(_blendImage->hMemDC, 0, 0,
//			_imageInfo->width, _imageInfo->height,
//			hdc, destX, destY, SRCCOPY);
//
//		//특정칼라를 제외하고 DC -> DC 사이로 고속복사 해주는 함수
//		GdiTransparentBlt(
//			_blendImage->hMemDC,	//복사될 DC
//			0,						//이미지 그려줄 시작X좌표(left)
//			0,						//이미지 그려줄 시작Y좌표(top)
//			_imageInfo->width,		//복사될 가로크기
//			_imageInfo->height,		//복사될 세로크기
//			_imageInfo->hMemDC,
//			0, 0,					//복사시작할 XY좌표
//			_imageInfo->width,		//복사할 가로/세로크기
//			_imageInfo->height,
//			_transColor				//복사때 제외할 칼라(뺄 칼라)
//		);
//
//		AlphaBlend(hdc, destX, destY, _imageInfo->width,
//			_imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
//			_blendFunc);
//	}
//	else
//	{
//		AlphaBlend(hdc, destX, destY, _imageInfo->width,
//			_imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
//			_blendFunc);
//	}
//}
//
//
//
//======================================================================================
//알파 블랜딩 이란
//배경이 있는 이미지 위에 다른이미지를 그릴경우 투명하게 비치는 효과를 내기 위해서
//알파라는 8비트의 새로운 값을 각 픽셀에 할당하여 
//배경의 RGB 컬러와  대상의 RGB 컬러를 혼합하여 표시하는 방법이다.
//
//알파블랭딩의 단점
//알파블랜딩을 할 경우 자연스러운 이미지 연출을 얻을수 있지만 매 픽셀하다 같은 연산을 해야되기 때문에
//CPU 부하가 심함!
//
//
////=====================================================================================
//
//쓰기위해 해야할것
//
//알파값을 저장할 변수 한개 선언.하지만 알파값변수는 함수에서 쓰일때 BYTE 이기 때문에 0~255 까지만 숫자 가능 하므로 int형으로 선언
//
//투명 범위는 0 ~255  중  0 은 완전투명   / 255는  불투명 
//
//즉 값이 0에 가까워질수록 이미지는 반투명하게 되고 0이면 투명하게된다.
//
//그러므로 업데이트 부분에서 알파값을 실시간으로 --변수; 하게되면 시간에 따라 그림이 투명해짐
//
//알파값이 0을 지나가면 아예 투명이므로 반짝반짝 하게 하기 위해서는 조건문으로 0이하가 됫을경우 다시 255로 돌리면 반짝반짝 하게 된다.
//
//투명하게 할 이미지는 랜더부분에서 그냥 image->render 가 아니라 image->alphaRender() 해야함
//image->alphaRender(hdc, 시작점의 X, 시작점의 Y, 알파값변수); 하면된다.


//========================================================================================
//활용방안

//이미지를 더 빠르게 반짝하게 하거나 더빠르게 투명화 하고 싶다면
//알파변수 -= 5;
//이런식으로  더 빠르게 투명화 시킬수 있다


//두개의 이미지를 자연스럽게 바꾸고 싶다면 하나는 알파값을 0 하나는 255를 주고 불값을 사용하여 
//특정 상태일때 한 이미지의 알파값은 ++  다른이미지는 -- 하게되면 자연스럽게 두 이미지는 교체된다

//==========================================================================================












