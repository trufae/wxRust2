#include <wx/ctrlsub.h>
#include "manual.h"

// wxList<T>
#define IMPL_WX_LIST_BINDING(wxclass)                       \
    wxclass##List *wxclass##List_new() {                    \
        return new wxclass##List();                         \
    }                                                       \
    void wxclass##List_delete(wxclass##List *self) {        \
        delete self;                                        \
    }                                                       \
    size_t wxclass##List_GetCount(wxclass##List *self) {    \
        return self->GetCount();                            \
    }                                                       \
    bool wxclass##List_IsEmpty(wxclass##List *self) {       \
        return self->IsEmpty();                             \
    }

IMPL_WX_LIST_BINDING(wxSizerItem);
IMPL_WX_LIST_BINDING(wxWindow);

int wxRustMessageBox(const wxString *message, const wxString *caption, int style, wxWindow *parent, int x, int y) {
    return wxMessageBox(*message, *caption, style, parent, x, y);
}
