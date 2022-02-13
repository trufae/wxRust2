#include "wx/include/wxrust.h"
#include "wx/include/wxrust2.h"

namespace wxrust {

// Constructors

// CLASS: wxObject
wxObject *NewObject() {
    return new wxObject();
}
wxObject *NewObject(const wxObject & other) {
    return new wxObject(other);
}

// CLASS: wxEvtHandler
wxEvtHandler *NewEvtHandler() {
    return new wxEvtHandler();
}

// CLASS: wxWindow
wxWindow *NewWindow() {
    return new wxWindow();
}
wxWindow *NewWindow(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size, int32_t style, const wxString & name) {
    return new wxWindow(parent, id, pos, size, style, name);
}

// CLASS: wxControl
wxControl *NewControl(wxWindow * parent, wxWindowID id, const wxPoint & pos, const wxSize & size, int32_t style, const wxValidator & validator, const wxString & name) {
    return new wxControl(parent, id, pos, size, style, validator, name);
}
wxControl *NewControl() {
    return new wxControl();
}

// CLASS: wxAnyButton
wxAnyButton *NewAnyButton() {
    return new wxAnyButton();
}

// CLASS: wxButton
wxButton *NewButton() {
    return new wxButton();
}
wxButton *NewButton(wxWindow * parent, wxWindowID id, const wxString & label, const wxPoint & pos, const wxSize & size, int32_t style, const wxValidator & validator, const wxString & name) {
    return new wxButton(parent, id, label, pos, size, style, validator, name);
}

// CLASS: wxNonOwnedWindow

// CLASS: wxTopLevelWindow
wxTopLevelWindow *NewTopLevelWindow() {
    return new wxTopLevelWindow();
}
wxTopLevelWindow *NewTopLevelWindow(wxWindow * parent, wxWindowID id, const wxString & title, const wxPoint & pos, const wxSize & size, int32_t style, const wxString & name) {
    return new wxTopLevelWindow(parent, id, title, pos, size, style, name);
}

// CLASS: wxFrame
wxFrame *NewFrame() {
    return new wxFrame();
}
wxFrame *NewFrame(wxWindow * parent, wxWindowID id, const wxString & title, const wxPoint & pos, const wxSize & size, int32_t style, const wxString & name) {
    return new wxFrame(parent, id, title, pos, size, style, name);
}

// CLASS: wxPoint
wxPoint *NewPoint() {
    return new wxPoint();
}
wxPoint *NewPoint(int x, int y) {
    return new wxPoint(x, y);
}
wxPoint *NewPoint(const wxRealPoint & pt) {
    return new wxPoint(pt);
}

// CLASS: wxSize
wxSize *NewSize() {
    return new wxSize();
}
wxSize *NewSize(int width, int height) {
    return new wxSize(width, height);
}

// CLASS: wxValidator
wxValidator *NewValidator() {
    return new wxValidator();
}

} // namespace wxrust

