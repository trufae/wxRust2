#pragma once
#include <wx/wx.h>

#define DECL_WX_LIST_BINDING(wxclass)                   \
    wxclass##List *wxclass##List_new();                 \
    void wxclass##List_delete(wxclass##List *self);     \
    size_t wxclass##List_GetCount(wxclass##List *self); \
    bool wxclass##List_IsEmpty(wxclass##List *self);

extern "C" {
    // wxList<T>
    DECL_WX_LIST_BINDING(wxSizerItem);
    DECL_WX_LIST_BINDING(wxWindow);

    int wxRustMessageBox(const wxString *message, const wxString *caption, int style, wxWindow *parent, int x, int y);

    // CLASS: wxItemContainer
    void wxItemContainer_delete(wxItemContainer *self);
    int wxItemContainer_Append(wxItemContainer * self, const wxString * item);
    int wxItemContainer_Append1(wxItemContainer * self, const wxString * item, void * client_data);
    int wxItemContainer_Append2(wxItemContainer * self, const wxString * item, wxClientData * client_data);
    int wxItemContainer_Append3(wxItemContainer * self, const wxArrayString * items);
    int wxItemContainer_Append5(wxItemContainer * self, const wxArrayString * items, void ** client_data);
    int wxItemContainer_Append6(wxItemContainer * self, const wxArrayString * items, wxClientData ** client_data);
    void wxItemContainer_Clear(wxItemContainer * self);
    void wxItemContainer_Delete(wxItemContainer * self, unsigned int n);
    wxClientData * wxItemContainer_DetachClientObject(wxItemContainer * self, unsigned int n);
    bool wxItemContainer_HasClientData(const wxItemContainer * self);
    bool wxItemContainer_HasClientObjectData(const wxItemContainer * self);
    bool wxItemContainer_HasClientUntypedData(const wxItemContainer * self);
    void * wxItemContainer_GetClientData(const wxItemContainer * self, unsigned int n);
    wxClientData * wxItemContainer_GetClientObject(const wxItemContainer * self, unsigned int n);
    void wxItemContainer_SetClientData(wxItemContainer * self, unsigned int n, void * data);
    void wxItemContainer_SetClientObject(wxItemContainer * self, unsigned int n, wxClientData * data);
    int wxItemContainer_Insert(wxItemContainer * self, const wxString * item, unsigned int pos);
    int wxItemContainer_Insert1(wxItemContainer * self, const wxString * item, unsigned int pos, void * client_data);
    int wxItemContainer_Insert2(wxItemContainer * self, const wxString * item, unsigned int pos, wxClientData * client_data);
    int wxItemContainer_Insert3(wxItemContainer * self, const wxArrayString * items, unsigned int pos);
    int wxItemContainer_Insert5(wxItemContainer * self, const wxArrayString * items, unsigned int pos, void ** client_data);
    int wxItemContainer_Insert6(wxItemContainer * self, const wxArrayString * items, unsigned int pos, wxClientData ** client_data);
    void wxItemContainer_Set(wxItemContainer * self, const wxArrayString * items);
    void wxItemContainer_Set2(wxItemContainer * self, const wxArrayString * items, void ** client_data);
    void wxItemContainer_Set3(wxItemContainer * self, const wxArrayString * items, wxClientData ** client_data);

    wxItemContainer *wxChoice_AsItemContainer(wxChoice * obj);

    wxItemContainerImmutable *wxRadioBox_AsItemContainerImmutable(wxRadioBox * obj);

    wxTextEntry *wxTextCtrl_AsTextEntry(wxTextCtrl * obj);
}
