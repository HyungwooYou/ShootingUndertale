#pragma once

//// ======================�߰��Ȱ�==========================

//image.h�� �߰��Ȱ�
//BLENDFUNCTION		_blendFunc;		//���ĺ��� ���� �Լ��� ����
//LPIMAGE_INFO		_blendImage;	//����ó���� �̹���
//
//void alphaRender(HDC hdc, BYTE alpha);
//void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
//
//
//
//image.cpp    init�� �߰��Ȱ�
////���ĺ��� ������.
//	//���� + ġ���̴� �����ؼ� ����
//	_blendFunc.BlendFlags = 0;
//_blendFunc.AlphaFormat = 0;
//_blendFunc.BlendOp = AC_SRC_OVER;	//<-- �̰� �� �� �����غ����� ������					SRC = �����̸�
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
//image.cpp   release�� �߰��Ȱ�
////�� init�Լ��� ���ĺ��� ó���� �̹����� �Ҵ�ǰ� �ֱ� ������
//		//���� ����������մϴ�!!!!!!!!!!!!!!!
//	SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
//DeleteObject(_blendImage->hBit);
//DeleteDC(_blendImage->hMemDC);
//
//
//void image::alphaRender(HDC hdc, BYTE alpha)
//{
//	//������ �����սô�
//	//BYTE�� ���ĺ��� ��ġ���̴�. 0 ~ 255�� ������ ������
//	//���� �������� ������ ����
//
//	//�̰��� �ؾ� ���İ��� �����!!!
//	_blendFunc.SourceConstantAlpha = alpha;
//
//	if (_trans)
//	{
//		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
//			hdc, 0, 0, SRCCOPY);
//
//		//Ư��Į�� �����ϰ� DC -> DC ���̷� ��Ӻ��� ���ִ� �Լ�
//		GdiTransparentBlt(
//			_blendImage->hMemDC,	//����� DC
//			0,						//�̹��� �׷��� ����X��ǥ(left)
//			0,						//�̹��� �׷��� ����Y��ǥ(top)
//			_imageInfo->width,		//����� ����ũ��
//			_imageInfo->height,		//����� ����ũ��
//			_imageInfo->hMemDC,
//			0, 0,					//��������� XY��ǥ
//			_imageInfo->width,		//������ ����/����ũ��
//			_imageInfo->height,
//			_transColor				//���綧 ������ Į��(�� Į��)
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
//	//������ �����սô�
//	//BYTE�� ���ĺ��� ��ġ���̴�. 0 ~ 255�� ������ ������
//	//���� �������� ������ ����
//
//	//�̰��� �ؾ� ���İ��� �����!!!
//	_blendFunc.SourceConstantAlpha = alpha;
//
//	if (_trans)
//	{
//		BitBlt(_blendImage->hMemDC, 0, 0,
//			_imageInfo->width, _imageInfo->height,
//			hdc, destX, destY, SRCCOPY);
//
//		//Ư��Į�� �����ϰ� DC -> DC ���̷� ��Ӻ��� ���ִ� �Լ�
//		GdiTransparentBlt(
//			_blendImage->hMemDC,	//����� DC
//			0,						//�̹��� �׷��� ����X��ǥ(left)
//			0,						//�̹��� �׷��� ����Y��ǥ(top)
//			_imageInfo->width,		//����� ����ũ��
//			_imageInfo->height,		//����� ����ũ��
//			_imageInfo->hMemDC,
//			0, 0,					//��������� XY��ǥ
//			_imageInfo->width,		//������ ����/����ũ��
//			_imageInfo->height,
//			_transColor				//���綧 ������ Į��(�� Į��)
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
//���� ���� �̶�
//����� �ִ� �̹��� ���� �ٸ��̹����� �׸���� �����ϰ� ��ġ�� ȿ���� ���� ���ؼ�
//���Ķ�� 8��Ʈ�� ���ο� ���� �� �ȼ��� �Ҵ��Ͽ� 
//����� RGB �÷���  ����� RGB �÷��� ȥ���Ͽ� ǥ���ϴ� ����̴�.
//
//���ĺ����� ����
//���ĺ����� �� ��� �ڿ������� �̹��� ������ ������ ������ �� �ȼ��ϴ� ���� ������ �ؾߵǱ� ������
//CPU ���ϰ� ����!
//
//
////=====================================================================================
//
//�������� �ؾ��Ұ�
//
//���İ��� ������ ���� �Ѱ� ����.������ ���İ������� �Լ����� ���϶� BYTE �̱� ������ 0~255 ������ ���� ���� �ϹǷ� int������ ����
//
//���� ������ 0 ~255  ��  0 �� ��������   / 255��  ������ 
//
//�� ���� 0�� ����������� �̹����� �������ϰ� �ǰ� 0�̸� �����ϰԵȴ�.
//
//�׷��Ƿ� ������Ʈ �κп��� ���İ��� �ǽð����� --����; �ϰԵǸ� �ð��� ���� �׸��� ��������
//
//���İ��� 0�� �������� �ƿ� �����̹Ƿ� ��¦��¦ �ϰ� �ϱ� ���ؼ��� ���ǹ����� 0���ϰ� ������� �ٽ� 255�� ������ ��¦��¦ �ϰ� �ȴ�.
//
//�����ϰ� �� �̹����� �����κп��� �׳� image->render �� �ƴ϶� image->alphaRender() �ؾ���
//image->alphaRender(hdc, �������� X, �������� Y, ���İ�����); �ϸ�ȴ�.


//========================================================================================
//Ȱ����

//�̹����� �� ������ ��¦�ϰ� �ϰų� �������� ����ȭ �ϰ� �ʹٸ�
//���ĺ��� -= 5;
//�̷�������  �� ������ ����ȭ ��ų�� �ִ�


//�ΰ��� �̹����� �ڿ������� �ٲٰ� �ʹٸ� �ϳ��� ���İ��� 0 �ϳ��� 255�� �ְ� �Ұ��� ����Ͽ� 
//Ư�� �����϶� �� �̹����� ���İ��� ++  �ٸ��̹����� -- �ϰԵǸ� �ڿ������� �� �̹����� ��ü�ȴ�

//==========================================================================================












