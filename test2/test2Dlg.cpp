
// test2Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Ctest2Dlg �Ի���




IMPLEMENT_DYNAMIC(Ctest2Dlg, CDialogEx);

Ctest2Dlg::Ctest2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

Ctest2Dlg::~Ctest2Dlg()
{
	// ����öԻ������Զ���������
	//  ���˴���ָ��öԻ���ĺ���ָ������Ϊ NULL���Ա�
	//  �˴���֪���öԻ����ѱ�ɾ����
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


// Ctest2Dlg ��Ϣ�������

BOOL Ctest2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	CRect rect;   
  
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
    m_list_report.GetClientRect(&rect);   
  
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
    m_list_report.SetExtendedStyle(m_list_report.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // Ϊ�б���ͼ�ؼ��������   
    m_list_report.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/3, 0);   
    m_list_report.InsertColumn(1, _T("���"), LVCFMT_CENTER, rect.Width()/3, 1);   
    m_list_report.InsertColumn(2, _T("���֤"), LVCFMT_CENTER, rect.Width()/3, 2);   
  
    // ���б���ͼ�ؼ��в����б���������б������ı�   
    m_list_report.InsertItem(0, _T("����"));   
    m_list_report.SetItemText(0, 1, _T("0001"));   
    m_list_report.SetItemText(0, 2, _T("510104190001011111"));   
    m_list_report.InsertItem(1, _T("����"));   
    m_list_report.SetItemText(1, 1, _T("0002"));   
    m_list_report.SetItemText(1, 2, _T("510104190001011111"));   
    m_list_report.InsertItem(2, _T("����"));   
    m_list_report.SetItemText(2, 1, _T("00003"));   
    m_list_report.SetItemText(2, 2, _T("510104190001011111"));   


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���û��ر� UI ʱ������������Ա���������ĳ��
//  �������Զ�����������Ӧ�˳�����Щ
//  ��Ϣ�������ȷ����������: �����������ʹ�ã�
//  ������ UI�������ڹرնԻ���ʱ��
//  �Ի�����Ȼ�ᱣ�������

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
	// �����������Ա�����������Զ���
	//  �������Իᱣ�ִ�Ӧ�ó���
	//  ʹ�Ի���������������� UI ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void Ctest2Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_id.SetWindowText(_T("0001"));
	m_company.SetWindowText(_T("�к�վ"));
	m_name.SetWindowText(_T("Jack"));
	m_identity.SetWindowText(_T("510119198812121212"));
	

}


void Ctest2Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_gross_weight.SetWindowText(_T("128"));
	m_tare.SetWindowText(_T("118"));
}


void Ctest2Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ������ר�õĴ�������
	// �ڷ���ǰ���ص�¼����
	CLoginDlg dlg;
	dlg.DoModal();

	return 0;
}
