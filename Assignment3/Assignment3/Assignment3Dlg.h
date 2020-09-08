
// Assignment3Dlg.h : header file
//

#pragma once


// CAssignment3Dlg dialog
class CAssignment3Dlg : public CDialogEx
{
// Construction
public:
	CAssignment3Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ASSIGNMENT3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit DataFileNameBox;
	afx_msg void OnBnClickedButtonInitializeSimulation();
	CEdit GenusSpeciesBox;
	CEdit CommonNameBox;
	CEdit MasterGenesBox;
	CEdit Parent1GenotypeBox;
	CEdit Parent2GenotypeBox;
	CEdit ResultsBox;
	CEdit NumOffspringBox;
	afx_msg void OnBnClickedButtonRunExperiment();
	CEdit OutputFileNameBox;
	afx_msg void OnBnClickedButtonSaveResults();
	CEdit NumChromosomesBox;
};
