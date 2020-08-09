/**
 * @file  PluginsListDlg.h
 *
 * @brief Declaration file for PluginsList dialog
 */
#pragma once

#include "TrDialogs.h"
#include "UnicodeString.h"

class PluginInfo;

/**
 * @brief A dialog listing plugins.
 * This dialog shows a list of currently available plugins. In addition
 * to the plugin (file)name it shows plugin type and description. The
 * dialog also has a control to enable/disable plugins.
 */
class PluginsListDlg : public CTrDialog
{
	DECLARE_DYNAMIC(PluginsListDlg)

public:
	explicit PluginsListDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PluginsListDlg();

// Dialog Data
	enum { IDD = IDD_PLUGINS_LIST };

protected:
	void InitList();
	void AddPlugins();
	void AddPluginsToList(const wchar_t *pluginEvent, const String& pluginType);
	PluginInfo *GetSelectedPluginInfo() const;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	afx_msg BOOL OnInitDialog() override;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedPluginSettings();
	afx_msg void OnBnClickedFileFiltesDefaults();
	afx_msg void OnLVNItemChanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLVNItemChanging(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDropDownPatterns();
	afx_msg void OnCloseUpPatterns();
	DECLARE_MESSAGE_MAP()

public:
	CComboBox m_comboPatterns;
	CListCtrl m_list; /**< A list control for plugins. */	
};
