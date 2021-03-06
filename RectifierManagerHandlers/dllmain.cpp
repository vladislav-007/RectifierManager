// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "RectifierManagerHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CRectifierManagerHandlersModule _AtlModule;

class CRectifierManagerHandlersApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CRectifierManagerHandlersApp, CWinApp)
END_MESSAGE_MAP()

CRectifierManagerHandlersApp theApp;

BOOL CRectifierManagerHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CRectifierManagerHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
