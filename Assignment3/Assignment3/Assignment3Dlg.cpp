
// Assignment3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Assignment3.h"
#include "Assignment3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString fileName;
Organism parent1;
Organism parent2;
DataPrinter printer;
std::vector <GeneShared> sharedGenes;
bool set = false;
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


// CAssignment3Dlg dialog



CAssignment3Dlg::CAssignment3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ASSIGNMENT3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAssignment3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, DataFileNameBox);
	DDX_Control(pDX, IDC_EDIT2, GenusSpeciesBox);
	DDX_Control(pDX, IDC_EDIT3, CommonNameBox);
	DDX_Control(pDX, IDC_EDIT7, MasterGenesBox);
	DDX_Control(pDX, IDC_EDIT8, Parent1GenotypeBox);
	DDX_Control(pDX, IDC_EDIT9, Parent2GenotypeBox);
	DDX_Control(pDX, IDC_EDIT10, ResultsBox);
	DDX_Control(pDX, IDC_EDIT5, NumOffspringBox);
	DDX_Control(pDX, IDC_EDIT6, OutputFileNameBox);
	DDX_Control(pDX, IDC_EDIT4, NumChromosomesBox);
}

BEGIN_MESSAGE_MAP(CAssignment3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAssignment3Dlg::OnBnClickedButtonInitializeSimulation)
	ON_BN_CLICKED(IDC_BUTTON2, &CAssignment3Dlg::OnBnClickedButtonRunExperiment)
	ON_BN_CLICKED(IDC_BUTTON3, &CAssignment3Dlg::OnBnClickedButtonSaveResults)
END_MESSAGE_MAP()


// CAssignment3Dlg message handlers

BOOL CAssignment3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetWindowText("Mendelian Genetics Simulator");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAssignment3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAssignment3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAssignment3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAssignment3Dlg::OnBnClickedButtonInitializeSimulation()
{
	//const char * fileName = new const char[20];
	if (set) {
		MessageBoxA("You have already inputted a file.", "File already input.", MB_OK | MB_ICONWARNING);
		return;
	}
	set = true;
	DataFileNameBox.GetWindowTextA(fileName);
	GeneticsSimDataParser *genetics = genetics->getInstance();
	GeneFactory *geneFactory = geneFactory->getInstance();
	OrganismFactory *organismFactory = organismFactory->getInstance();
	genetics->initDataFile(fileName);
	char * trait = new char[64];
	char * domDesc = new char[64];
	char * domSymbol = new char[64];
	char * recDesc = new char[64];
	char * recSymbol = new char[64];
	double * coChance = new double;
	//std::vector <GeneShared> sharedGenes;
	sharedGenes.clear();
	for (int i = 0; i < genetics->getGeneCount(); i++) {
		genetics->getGeneData(trait, domDesc, domSymbol, recDesc, recSymbol, coChance);
		sharedGenes.push_back(geneFactory->buildGeneShared(trait, domDesc, domSymbol, recDesc, recSymbol, coChance));
	}
	GenusSpeciesBox.SetWindowTextA(genetics->getScientificName());
	CommonNameBox.SetWindowTextA(genetics->getCommonName());
	CString ChromosomeCount;
	ChromosomeCount.Format("%i", genetics->getChromosomeCount());
	NumChromosomesBox.SetWindowTextA(ChromosomeCount);
	parent1 = organismFactory->buildOrganism(1, sharedGenes, genetics);
	parent2 = organismFactory->buildOrganism(2, sharedGenes, genetics);
	printer.setParents(parent1, parent2);
	CString master(printer.masterGenes().c_str());
	MasterGenesBox.SetWindowTextA(master);
	CString parent1Info(printer.parent1Info().c_str());
	Parent1GenotypeBox.SetWindowTextA(parent1Info);
	CString parent2Info(printer.parent2Info().c_str());
	Parent2GenotypeBox.SetWindowTextA(parent2Info);
	// TODO: Add your control notification handler code here
}


void CAssignment3Dlg::OnBnClickedButtonRunExperiment()
{

	printer.setParents(parent1, parent2);
	CString experimentNumString;
	NumOffspringBox.GetWindowTextA(experimentNumString);
	if (atoi(experimentNumString) <= 0 || atoi(experimentNumString) > 1000) {
		MessageBoxA("You must enter a number of offspring between 1-1000.", "Invalid Offspring Count", MB_OK | MB_ICONWARNING);
		return;
	}
	printer.setOffspringNum(atoi(experimentNumString));
	CString squareResults(printer.squareResults().c_str());
	ResultsBox.SetWindowTextA(squareResults);
	// TODO: Add your control notification handler code here
}


void CAssignment3Dlg::OnBnClickedButtonSaveResults()
{
	CString saveFileName;
	OutputFileNameBox.GetWindowTextA(saveFileName);
	std::ofstream file;
	file.open(saveFileName, std::ios_base::app);
	CString result;
	ResultsBox.GetWindowTextA(result);
	file << result;
	file.close();

}
