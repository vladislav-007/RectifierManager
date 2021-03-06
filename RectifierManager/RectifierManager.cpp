
// RectifierManager.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "RectifierManager.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "RectifierManagerDoc.h"
#include "RectifierManagerView.h"
#include <vector>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRectifierManagerApp

BEGIN_MESSAGE_MAP(CRectifierManagerApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CRectifierManagerApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_FILE_OPEN, &CRectifierManagerApp::OnFileOpen)
	ON_COMMAND(ID_MENU_COM_PORT, &CRectifierManagerApp::OnMenuComPort)
END_MESSAGE_MAP()


// CRectifierManagerApp construction

CRectifierManagerApp::CRectifierManagerApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("RectifierManager.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CRectifierManagerApp object

CRectifierManagerApp theApp;


// CRectifierManagerApp initialization

BOOL CRectifierManagerApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_RectifierManagerTYPE,
		RUNTIME_CLASS(CRectifierManagerDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CRectifierManagerView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	// call DragAcceptFiles only if there's a suffix
	//  In an MDI app, this should occur immediately after setting m_pMainWnd
	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::FileNew)   // actually none
		cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CRectifierManagerApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CRectifierManagerApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CRectifierManagerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CRectifierManagerApp message handlers





void CRectifierManagerApp::OnFileOpen()
{
	// TODO: Add your command handler code here
	OutputDebugStringW(L"My output string.");
	CWinApp::OnFileOpen();
	

}

void DetectComPorts(std::vector<std::wstring> & ports, size_t upperLimit = 128)
{
	for (size_t i = 1; i <= upperLimit; i++)
	{
		TCHAR strPort[32] = { 0 };
		swprintf_s(strPort, _T("\\\\.\\COM%d"), i);

		DWORD dwSize = 0;
		LPCOMMCONFIG lpCC = (LPCOMMCONFIG) new BYTE[1];
		BOOL ret = GetDefaultCommConfig(strPort, lpCC, &dwSize);
		delete[] lpCC;

		lpCC = (LPCOMMCONFIG) new BYTE[dwSize];
		ret = GetDefaultCommConfig(strPort, lpCC, &dwSize);
		delete[] lpCC;
		std::wstring str(strPort);
		if (ret) ports.push_back(str);
	}
}

void SelectComPort(std::vector<CString> & portNames) //added fucntion to find the present serial ports of the system; 
{
	const DWORD maxSize = 50000;
	WCHAR lpTargetPath[maxSize]; // buffer to store the path of the COMPORTS
	DWORD test;
	bool gotPort = 0; // in case the port is not found

	for (int i = 0; i<255; i++) // checking ports from COM0 to COM255
	{
		CString str;
		str.Format(_T("%d"), i);
		CString ComName = CString("COM") + CString(str); // converting to COM0, COM1, COM2

		test = QueryDosDevice(ComName, (LPWSTR)lpTargetPath, maxSize);

		// Test the return value and error if any
		if (test != 0) //QueryDosDevice returns zero if it didn't find an object
		{
			portNames.push_back((CString)ComName); // add to the ComboBox
			gotPort = 1; // found port
		}
		DWORD res = ::GetLastError();
		res = ::GetLastError();
		if (res == ERROR_INSUFFICIENT_BUFFER) //in case buffer got filled
		{
			lpTargetPath[10000]; // in case the buffer got filled, increase size of the buffer.
			continue;
		}

	}

	if (!gotPort) // if not port
		portNames.push_back((CString)"No Active Ports Found"); // to display error message incase no ports found

}

void CRectifierManagerApp::OnMenuComPort()
{
	// TODO: Add your command handler code here
	std::vector<CString> names;
	SelectComPort(names);
	std::vector< std::wstring >  ports;
	DetectComPorts(ports);
	COMMCONFIG comm;
	HWND hWnd = AfxGetMainWnd()->m_hWnd;
	CommConfigDialog(L"COM1", hWnd, &comm);
}
