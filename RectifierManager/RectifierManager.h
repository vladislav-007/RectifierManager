
// RectifierManager.h : main header file for the RectifierManager application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRectifierManagerApp:
// See RectifierManager.cpp for the implementation of this class
//

class CRectifierManagerApp : public CWinApp
{
public:
	CRectifierManagerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	afx_msg void OnFileOpen();
	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnMenuComPort();
};

extern CRectifierManagerApp theApp;
