
// test2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test2.h"
#include "test2Dlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest2Dlg 对话框




IMPLEMENT_DYNAMIC(Ctest2Dlg, CDialogEx);

Ctest2Dlg::Ctest2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

Ctest2Dlg::~Ctest2Dlg()
{
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void Ctest2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, m_list_report);
	DDX_Control(pDX, IDC_EDIT_NAME, m_name);
	DDX_Control(pDX, IDC_EDIT_ID, m_id);
	DDX_Control(pDX, IDC_EDIT_IDENTITY, m_identity);
	DDX_Control(pDX, IDC_EDIT_COMPANY, m_company);
	DDX_Control(pDX, IDC_EDIT_GROSS_WEIGHT, m_gross_weight);
	DDX_Control(pDX, IDC_EDIT_TARE, m_tare);
}

BEGIN_MESSAGE_MAP(Ctest2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST4, &Ctest2Dlg::OnLvnItemchangedList4)
	ON_BN_CLICKED(IDC_BUTTON5, &Ctest2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Ctest2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest2Dlg::OnBnClickedButton1)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// Ctest2Dlg 消息处理程序

BOOL Ctest2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    m_list_report.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_list_report.SetExtendedStyle(m_list_report.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // 为列表视图控件添加三列   
    m_list_report.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width()/3, 0);   
    m_list_report.InsertColumn(1, _T("编号"), LVCFMT_CENTER, rect.Width()/3, 1);   
    m_list_report.InsertColumn(2, _T("身份证"), LVCFMT_CENTER, rect.Width()/3, 2);   
  
    // 在列表视图控件中插入列表项，并设置列表子项文本   
    m_list_report.InsertItem(0, _T("张三"));   
    m_list_report.SetItemText(0, 1, _T("0001"));   
    m_list_report.SetItemText(0, 2, _T("510104190001011111"));   
    m_list_report.InsertItem(1, _T("李四"));   
    m_list_report.SetItemText(1, 1, _T("0002"));   
    m_list_report.SetItemText(1, 2, _T("510104190001011111"));   
    m_list_report.InsertItem(2, _T("王五"));   
    m_list_report.SetItemText(2, 1, _T("00003"));   
    m_list_report.SetItemText(2, 2, _T("510104190001011111"));   


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void Ctest2Dlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void Ctest2Dlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void Ctest2Dlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL Ctest2Dlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void Ctest2Dlg::OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Ctest2Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_id.SetWindowText(_T("0001"));
	m_company.SetWindowText(_T("中和站"));
	m_name.SetWindowText(_T("Jack"));
	m_identity.SetWindowText(_T("510119198812121212"));
	

}


void Ctest2Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_gross_weight.SetWindowText(_T("128"));
	m_tare.SetWindowText(_T("118"));
}


void Ctest2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str,str2,str3;
	m_name.GetWindowText(str);
	m_id.GetWindowText(str2);
	m_identity.GetWindowText(str3);
	m_list_report.InsertItem(0, str);   
    m_list_report.SetItemText(0, 1, str2);   
    m_list_report.SetItemText(0, 2, str3);
}


int Ctest2Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	// 在返回前加载登录界面
	CLoginDlg dlg;
	dlg.DoModal();

	return 0;
}
