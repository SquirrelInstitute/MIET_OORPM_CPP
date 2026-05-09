
// lab2_2.h : main header file for the lab2_2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Clab22App:
// See lab2_2.cpp for the implementation of this class
//

class Clab22App : public CWinApp
{
public:
	Clab22App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab22App theApp;
