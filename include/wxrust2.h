#pragma once
#include <wx/wx.h>

#include "rust/cxx.h"
#include "wx/src/generated.rs.h"


namespace wxrust {

// CLASS: wxObject
wxObject *NewObject();
wxObject *NewObject1(const wxObject & other);

// CLASS: wxEvtHandler
wxEvtHandler *NewEvtHandler();

// CLASS: wxWindow
wxWindow *NewWindow();
wxWindow *NewWindow1(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size, int64_t style, const wxString & name);

// CLASS: wxControl
wxControl *NewControl(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size, int64_t style, const wxValidator & validator, const wxString & name);
wxControl *NewControl1();

// CLASS: wxAnyButton
wxAnyButton *NewAnyButton();

// CLASS: wxButton
wxButton *NewButton();
wxButton *NewButton1(wxWindow * parent, wxWindowID id, const wxString & label, const wxPoint & pos, const wxSize & size, int64_t style, const wxValidator & validator, const wxString & name);

} // namespace wxrust

