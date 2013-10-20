// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test2.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
	, m_user(_T(""))
	, m_password(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_USER, m_user);

	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedOk()
{
	this->UpdateData(true);
     CWnd *pWnd = NULL;
     // ��֤�û����������Ƿ���ȷ
     if (this->m_user != "test")
     {
         MessageBox(_T("�û����������������룡"));
         m_user = "";
         pWnd = GetDlgItem(IDC_EDIT_USER); // ��ȡIDC_USER�Ŀؼ�ָ��
         pWnd->SetFocus(); // ���ý���
         UpdateData(false);
     }
     else if (this->m_password != "test")
     {
         MessageBox(_T("����������������룡"));
         m_password = "";
         pWnd = GetDlgItem(IDC_EDIT_PASSWORD);
         pWnd->SetFocus();
         UpdateData(false);
     }
     else
     {
         CDialog::OnOK();
     }
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxGetMainWnd()->PostMessage(WM_QUIT); // ����WM_QUIT��Ϣ�˳�����
	CDialog::OnCancel();
}
