
// MFCblack.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCblackApp: 
// �йش����ʵ�֣������ MFCblack.cpp
//

class CMFCblackApp : public CWinApp
{
public:
	CMFCblackApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCblackApp theApp;