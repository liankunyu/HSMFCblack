
// MFCblackDlg.h : ͷ�ļ�
//

#pragma once


// CMFCblackDlg �Ի���
class CMFCblackDlg : public CDialogEx
{
// ����
public:
	CMFCblackDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBLACK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int tm[10] = { 0,0,0,0,0,0,0,0,0,0 };
	CString tem[30] = {L"0"};
	CString temp[10] = {L"0"};
	CString CSnum[20] = { L"0",L"1",L"2",L"3",L"4",L"5", L"6", L"7", L"8", L"9" }; //����
	CString Sstr[20] = { L"C",L"N",L"M",L"H",L"U",L"X", L"L", L"S", L"R", L"J" };  //�ͻ���Ŷ�Ӧ����ĸ
	CString CSstr[20] = { L"L",L"K",L"Y",L"B",L"I",L"E", L"V", L"O", L"T", L"Q" }; //���ڶ�Ӧ����ĸ
	afx_msg void OnBnClickedButton1();
	CString m_cstr1;
	CString m_cstr2;
	afx_msg void OnBnClickedButton2();
	CString m_cstr3;
	int Remainder;
};
