
// Assignment3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <string>
#include "GeneticsSimDataParser.h";
#include "GeneFactory.h";
#include "ChromosomeFactory.h";
#include "OrganismFactory.h";
#include "DataPrinter.h";
#include <fstream>
// CAssignment3App:
// See Assignment3.cpp for the implementation of this class
//

class CAssignment3App : public CWinApp
{
public:
	CAssignment3App();
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAssignment3App theApp;
