#include "stdafx.h"
#include "item.h"



item::item()
{
}


item::~item()
{
}

HRESULT item::init()
{

	return S_OK;
}

void item::release()
{
}

void item::update(int goLR)
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); _viitem++)
	{
		_viitem->itemcount++;
		if (_viitem->itemmove == false)
		{
			if (_viitem->itemcount > 50)
			{
				_viitem->itemmove = true;
				_viitem->itemcount = 0;
			}
		}	
		if (_viitem->itemmove == true)
		{
			if (_viitem->itemcount > 50)
			{
				_viitem->itemmove = false;
				_viitem->itemcount = 0;
			}
		}

		if (_viitem->itemmove == false)
		{
			_viitem->y -= 0.1;
		}
		else if(_viitem->itemmove == true)
		{
			_viitem->y += 0.1;
		}


		_viitem->rc = RectMakeCenter(_viitem->x, _viitem->y,30,30);
		if (goLR == 2)
		{
			_viitem->x -= 3;
		}
		if (goLR == 3)
		{
			_viitem->x += 3;
		}
	}
}

void item::render()
{
	for (_viitem = _vitem.begin(); _viitem != _vitem.end(); _viitem++)
	{
		if (_viitem->itemNum == 1)
		{
			IMAGEMANAGER->findImage("아이템하트")->render(getMemDC(),_viitem->x,_viitem->y,0,0,30,30);
		}
		if (_viitem->itemNum == 2)
		{
			IMAGEMANAGER->findImage("아이템하트")->render(getMemDC(), _viitem->x, _viitem->y, 30, 0, 30, 30);
		}
		if (_viitem->itemNum == 3)
		{
			IMAGEMANAGER->findImage("아이템하트")->render(getMemDC(), _viitem->x, _viitem->y, 60, 0, 30, 30);
		}
		//Rectangle(getMemDC(), _viitem->rc);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8))
	{
		if (checkrect == true)
		{
			checkrect = false;
		}
		else if (checkrect == false)
		{
			checkrect = true;
		}
	}
	if (checkrect == true)
	{
		for (_viitem = _vitem.begin(); _viitem != _vitem.end(); _viitem++)
		{
			Rectangle(getMemDC(), _viitem->rc);
		}
	}
}

void item::itemDrop(int rndNumber , float x, float y)
{
	tagitem itemdrop;
	ZeroMemory(&itemdrop, sizeof(itemdrop));
	itemdrop._image = IMAGEMANAGER->addImage("아이템하트", "itemimage.bmp", 90, 30, true, RGB(255, 0, 255));
	itemdrop.x = x;
	itemdrop.y = y;
	itemdrop.rc = RectMakeCenter(itemdrop.x, itemdrop.y,30,30);
	itemdrop.itemNum = RND->getFromIntTo(1,4);

	_vitem.push_back(itemdrop);
}
