#pragma once
#include <wx/wx.h>
#include <wx/filename.h>

typedef wxDateTime::TimeZone TimeZone;
typedef wxDateTime::Tm       Tm;
typedef wxDateTime::WeekDay  WeekDay;

extern "C" {

// CLASS: wxDateTime
void wxDateTime_delete(wxDateTime *self);
wxDateTime *wxDateTime_new();
wxDateTime *wxDateTime_new1(const wxDateTime * date);
wxDateTime *wxDateTime_new4(double jdn);
wxDateTime * wxDateTime_ResetTime(wxDateTime * self);
wxDateTime * wxDateTime_Set2(wxDateTime * self, const Tm * tm);
wxDateTime * wxDateTime_Set3(wxDateTime * self, double jdn);
wxDateTime * wxDateTime_SetToCurrent(wxDateTime * self);
wxDateTime * wxDateTime_SetYear(wxDateTime * self, int year);
#ifdef __WXMSW__
wxDateTime * wxDateTime_SetFromMSWSysTime(wxDateTime * self, const struct _SYSTEMTIME * st);
void wxDateTime_GetAsMSWSysTime(const wxDateTime * self, struct _SYSTEMTIME * st);
#endif
int wxDateTime_GetCentury(const wxDateTime * self, const TimeZone * tz);
wxDateTime *wxDateTime_GetDateOnly(const wxDateTime * self);
#if wxCHECK_VERSION(3, 1, 0)
int wxDateTime_GetWeekBasedYear(const wxDateTime * self, const TimeZone * tz);
#endif
int wxDateTime_GetYear(const wxDateTime * self, const TimeZone * tz);
bool wxDateTime_IsValid(const wxDateTime * self);
bool wxDateTime_IsEarlierThan(const wxDateTime * self, const wxDateTime * datetime);
bool wxDateTime_IsEqualTo(const wxDateTime * self, const wxDateTime * datetime);
bool wxDateTime_IsEqualUpTo(const wxDateTime * self, const wxDateTime * dt, const wxTimeSpan * ts);
bool wxDateTime_IsLaterThan(const wxDateTime * self, const wxDateTime * datetime);
bool wxDateTime_IsSameDate(const wxDateTime * self, const wxDateTime * dt);
bool wxDateTime_IsSameTime(const wxDateTime * self, const wxDateTime * dt);
bool wxDateTime_IsStrictlyBetween(const wxDateTime * self, const wxDateTime * t1, const wxDateTime * t2);
bool wxDateTime_IsBetween(const wxDateTime * self, const wxDateTime * t1, const wxDateTime * t2);
wxDateTime * wxDateTime_Add1(wxDateTime * self, const wxDateSpan * diff);
wxDateTime * wxDateTime_Add3(wxDateTime * self, const wxTimeSpan * diff);
wxDateTime * wxDateTime_Subtract1(wxDateTime * self, const wxTimeSpan * diff);
wxDateTime * wxDateTime_Subtract3(wxDateTime * self, const wxDateSpan * diff);
wxString *wxDateTime_Format(const wxDateTime * self, const wxString * format, const TimeZone * tz);
wxString *wxDateTime_FormatDate(const wxDateTime * self);
wxString *wxDateTime_FormatISODate(const wxDateTime * self);
wxString *wxDateTime_FormatISOTime(const wxDateTime * self);
wxString *wxDateTime_FormatTime(const wxDateTime * self);
bool wxDateTime_ParseDateTime(wxDateTime * self, const wxString * datetime, wxString::const_iterator * end);
bool wxDateTime_ParseFormat(wxDateTime * self, const wxString * date, const wxString * format, const wxDateTime * date_def, wxString::const_iterator * end);
bool wxDateTime_ParseISODate(wxDateTime * self, const wxString * date);
bool wxDateTime_ParseISOTime(wxDateTime * self, const wxString * date);
bool wxDateTime_ParseRfc822Date(wxDateTime * self, const wxString * date, wxString::const_iterator * end);
bool wxDateTime_ParseTime(wxDateTime * self, const wxString * time, wxString::const_iterator * end);
double wxDateTime_GetJDN(const wxDateTime * self);
double wxDateTime_GetJulianDayNumber(const wxDateTime * self);
double wxDateTime_GetMJD(const wxDateTime * self);
double wxDateTime_GetModifiedJulianDayNumber(const wxDateTime * self);
double wxDateTime_GetRataDie(const wxDateTime * self);
wxDateTime *wxDateTime_FromTimezone(const wxDateTime * self, const TimeZone * tz, bool no_dst);
wxDateTime * wxDateTime_MakeFromTimezone(wxDateTime * self, const TimeZone * tz, bool no_dst);
wxDateTime * wxDateTime_MakeTimezone(wxDateTime * self, const TimeZone * tz, bool no_dst);
wxDateTime * wxDateTime_MakeUTC(wxDateTime * self, bool no_dst);
wxDateTime *wxDateTime_ToTimezone(const wxDateTime * self, const TimeZone * tz, bool no_dst);
wxDateTime *wxDateTime_ToUTC(const wxDateTime * self, bool no_dst);
int wxDateTime_ConvertYearToBC(int year);
void wxDateTime_GetAmPmStrings(wxString * am, wxString * pm);
int wxDateTime_GetCentury1(int year);
tm * wxDateTime_GetTmNow1();
#if wxCHECK_VERSION(3, 1, 0)
bool wxDateTime_GetFirstWeekDay(WeekDay * first_day);
#endif
wxDateTime *wxDateTime_Now();
wxDateTime *wxDateTime_Today();
wxDateTime *wxDateTime_UNow();

// CLASS: wxEvent
wxEvent * wxEvent_Clone(const wxEvent * self);
wxObject * wxEvent_GetEventObject(const wxEvent * self);
int wxEvent_GetId(const wxEvent * self);
wxObject * wxEvent_GetEventUserData(const wxEvent * self);
bool wxEvent_GetSkipped(const wxEvent * self);
long wxEvent_GetTimestamp(const wxEvent * self);
bool wxEvent_IsCommandEvent(const wxEvent * self);
void wxEvent_ResumePropagation(wxEvent * self, int propagation_level);
void wxEvent_SetEventObject(wxEvent * self, wxObject * object);
void wxEvent_SetId(wxEvent * self, int id);
void wxEvent_SetTimestamp(wxEvent * self, long time_stamp);
bool wxEvent_ShouldPropagate(const wxEvent * self);
void wxEvent_Skip(wxEvent * self, bool skip);
int wxEvent_StopPropagation(wxEvent * self);

// CLASS: wxEvtHandler
void wxEvtHandler_QueueEvent(wxEvtHandler * self, wxEvent * event);
void wxEvtHandler_AddPendingEvent(wxEvtHandler * self, const wxEvent * event);
bool wxEvtHandler_ProcessEvent(wxEvtHandler * self, wxEvent * event);
bool wxEvtHandler_ProcessEventLocally(wxEvtHandler * self, wxEvent * event);
bool wxEvtHandler_SafelyProcessEvent(wxEvtHandler * self, wxEvent * event);
void wxEvtHandler_ProcessPendingEvents(wxEvtHandler * self);
void wxEvtHandler_DeletePendingEvents(wxEvtHandler * self);
wxClientData * wxEvtHandler_GetClientObject(const wxEvtHandler * self);
void wxEvtHandler_SetClientObject(wxEvtHandler * self, wxClientData * data);
bool wxEvtHandler_GetEvtHandlerEnabled(const wxEvtHandler * self);
wxEvtHandler * wxEvtHandler_GetNextHandler(const wxEvtHandler * self);
wxEvtHandler * wxEvtHandler_GetPreviousHandler(const wxEvtHandler * self);
void wxEvtHandler_SetEvtHandlerEnabled(wxEvtHandler * self, bool enabled);
void wxEvtHandler_SetNextHandler(wxEvtHandler * self, wxEvtHandler * handler);
void wxEvtHandler_SetPreviousHandler(wxEvtHandler * self, wxEvtHandler * handler);
void wxEvtHandler_Unlink(wxEvtHandler * self);
bool wxEvtHandler_IsUnlinked(const wxEvtHandler * self);
void wxEvtHandler_AddFilter(wxEventFilter * filter);
void wxEvtHandler_RemoveFilter(wxEventFilter * filter);
wxEvtHandler *wxEvtHandler_new();

// CLASS: wxFileName
void wxFileName_delete(wxFileName *self);
wxFileName *wxFileName_new();
wxFileName *wxFileName_new1(const wxFileName * filename);
bool wxFileName_AppendDir(wxFileName * self, const wxString * dir);
void wxFileName_Assign(wxFileName * self, const wxFileName * filepath);
void wxFileName_AssignCwd(wxFileName * self, const wxString * volume);
void wxFileName_AssignHomeDir(wxFileName * self);
void wxFileName_AssignTempFileName(wxFileName * self, const wxString * prefix);
void wxFileName_AssignTempFileName1(wxFileName * self, const wxString * prefix, wxFile * file_temp);
void wxFileName_AssignTempFileName2(wxFileName * self, const wxString * prefix, wxFFile * file_temp);
void wxFileName_Clear(wxFileName * self);
void wxFileName_ClearExt(wxFileName * self);
bool wxFileName_DirExists(const wxFileName * self);
void wxFileName_DontFollowLink(wxFileName * self);
bool wxFileName_Exists(const wxFileName * self, int flags);
bool wxFileName_FileExists(const wxFileName * self);
size_t wxFileName_GetDirCount(const wxFileName * self);
wxArrayString *wxFileName_GetDirs(const wxFileName * self);
wxString *wxFileName_GetExt(const wxFileName * self);
wxString *wxFileName_GetFullName(const wxFileName * self);
wxString *wxFileName_GetLongPath(const wxFileName * self);
wxDateTime *wxFileName_GetModificationTime(const wxFileName * self);
wxString *wxFileName_GetName(const wxFileName * self);
wxString *wxFileName_GetShortPath(const wxFileName * self);
bool wxFileName_GetTimes(const wxFileName * self, wxDateTime * dt_access, wxDateTime * dt_mod, wxDateTime * dt_create);
wxString *wxFileName_GetVolume(const wxFileName * self);
bool wxFileName_HasExt(const wxFileName * self);
bool wxFileName_HasName(const wxFileName * self);
bool wxFileName_HasVolume(const wxFileName * self);
bool wxFileName_InsertDir(wxFileName * self, size_t before, const wxString * dir);
bool wxFileName_IsDir(const wxFileName * self);
bool wxFileName_IsDirReadable(const wxFileName * self);
bool wxFileName_IsDirWritable(const wxFileName * self);
bool wxFileName_IsFileExecutable(const wxFileName * self);
bool wxFileName_IsFileReadable(const wxFileName * self);
bool wxFileName_IsFileWritable(const wxFileName * self);
bool wxFileName_IsOk(const wxFileName * self);
bool wxFileName_Mkdir(const wxFileName * self, int perm, int flags);
void wxFileName_PrependDir(wxFileName * self, const wxString * dir);
void wxFileName_RemoveDir(wxFileName * self, size_t pos);
void wxFileName_RemoveLastDir(wxFileName * self);
#if wxCHECK_VERSION(3, 1, 0)
wxFileName *wxFileName_ResolveLink(wxFileName * self);
#endif
bool wxFileName_Rmdir(const wxFileName * self, int flags);
bool wxFileName_SetCwd(const wxFileName * self);
void wxFileName_SetEmptyExt(wxFileName * self);
void wxFileName_SetExt(wxFileName * self, const wxString * ext);
void wxFileName_SetFullName(wxFileName * self, const wxString * fullname);
void wxFileName_SetName(wxFileName * self, const wxString * name);
bool wxFileName_SetPermissions(wxFileName * self, int permissions);
bool wxFileName_SetTimes(const wxFileName * self, const wxDateTime * dt_access, const wxDateTime * dt_mod, const wxDateTime * dt_create);
void wxFileName_SetVolume(wxFileName * self, const wxString * volume);
bool wxFileName_ShouldFollowLink(const wxFileName * self);
bool wxFileName_Touch(const wxFileName * self);
wxString *wxFileName_CreateTempFileName(const wxString * prefix, wxFile * file_temp);
wxString *wxFileName_CreateTempFileName1(const wxString * prefix, wxFFile * file_temp);
bool wxFileName_DirExists1(const wxString * dir);
bool wxFileName_Exists1(const wxString * path, int flags);
bool wxFileName_FileExists1(const wxString * file);
wxString *wxFileName_GetCwd(const wxString * volume);
wxString *wxFileName_GetHomeDir();
wxString *wxFileName_GetTempDir();
bool wxFileName_IsDirReadable1(const wxString * dir);
bool wxFileName_IsDirWritable1(const wxString * dir);
bool wxFileName_IsFileExecutable1(const wxString * file);
bool wxFileName_IsFileReadable1(const wxString * file);
bool wxFileName_IsFileWritable1(const wxString * file);
bool wxFileName_Mkdir1(const wxString * dir, int perm, int flags);
bool wxFileName_Rmdir1(const wxString * dir, int flags);
bool wxFileName_SetCwd1(const wxString * cwd);
#if wxCHECK_VERSION(3, 1, 0)
wxFileName *wxFileName_URLToFileName(const wxString * url);
wxString *wxFileName_FileNameToURL(const wxFileName * filename);
#endif
wxString *wxFileName_StripExtension(const wxString * fullname);

// CLASS: wxObject
wxObject *wxObject_new();
wxObject *wxObject_new1(const wxObject * other);
wxClassInfo * wxObject_GetClassInfo(const wxObject * self);
wxObjectRefData * wxObject_GetRefData(const wxObject * self);
bool wxObject_IsKindOf(const wxObject * self, const wxClassInfo * info);
bool wxObject_IsSameAs(const wxObject * self, const wxObject * obj);
void wxObject_Ref(wxObject * self, const wxObject * clone);
void wxObject_SetRefData(wxObject * self, wxObjectRefData * data);
void wxObject_UnRef(wxObject * self);
void wxObject_UnShare(wxObject * self);

} // extern "C"

