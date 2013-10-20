// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test2.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

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


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedOk()
{
	this->UpdateData(true);
     CWnd *pWnd = NULL;
     // 验证用户名、密码是否正确
     if (this->m_user != "test")
     {
         MessageBox(_T("用户名错误，请重新输入！"));
         m_user = "";
         pWnd = GetDlgItem(IDC_EDIT_USER); // 获取IDC_USER的控件指针
         pWnd->SetFocus(); // 设置焦点
         UpdateData(false);
     }
     else if (this->m_password != "test")
     {
         MessageBox(_T("密码错误，请重新输入！"));
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
	// TODO: 在此添加控件通知处理程序代码
	AfxGetMainWnd()->PostMessage(WM_QUIT); // 发送WM_QUIT消息退出程序
	CDialog::OnCancel();
}
