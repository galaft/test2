
// test2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class Ctest2DlgAutoProxy;


// Ctest2Dlg �Ի���
class Ctest2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Ctest2Dlg);
	friend class Ctest2DlgAutoProxy;

// ����
public:
	Ctest2Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~Ctest2Dlg();

// �Ի�������
	enum { IDD = IDD_TEST2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	Ctest2DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult);
	// ���׼�¼����
	CListCtrl m_list_report;
	// ����
	CEdit m_name;
	// ��ũ���
	CEdit m_id;
	// ���֤
	CEdit m_identity;
	// ũ��
	CEdit m_company;
	afx_msg void OnBnClickedButton5();
	// ë��
	CEdit m_gross_weight;
	// Ƥ��
	CEdit m_tare;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
