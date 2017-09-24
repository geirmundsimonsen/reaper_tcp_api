constexpr int tcpbuflength = 100000;
char sendrecvbuf[tcpbuflength];
int(*functions[607])();
char charbuf0[65536];
char charbuf1[65536];

int call_AddMediaItemToTrack() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem* retval = AddMediaItemToTrack(tr);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_AddProjectMarker() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int wantidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = AddProjectMarker(proj, isrgn, pos, rgnend, name, wantidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_AddProjectMarker2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int wantidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int color = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = AddProjectMarker2(proj, isrgn, pos, rgnend, name, wantidx, color);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_AddRemoveReaScript() {
int buf_index = 4;
bool add = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int sectionID = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* scriptfn = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(scriptfn);
bool commit = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = AddRemoveReaScript(add, sectionID, scriptfn, commit);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_AddTakeToMediaItem() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem_Take* retval = AddTakeToMediaItem(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_AddTempoTimeSigMarker() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double timepos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double bpm = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int timesig_num = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int timesig_denom = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool lineartempochange = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = AddTempoTimeSigMarker(proj, timepos, bpm, timesig_num, timesig_denom, lineartempochange);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_adjustZoom() {
int buf_index = 4;
double amt = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int forceset = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool doupd = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int centermode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
adjustZoom(amt, forceset, doupd, centermode);
buf_index = 0;
return buf_index; 
}

int call_AnyTrackSolo() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = AnyTrackSolo(proj);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_APIExists() {
int buf_index = 4;
const char* function_name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(function_name);
bool retval = APIExists(function_name);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_APITest() {
int buf_index = 4;
APITest();
buf_index = 0;
return buf_index; 
}

int call_ApplyNudge() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
int nudgeflag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int nudgewhat = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int nudgeunits = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double value = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool reverse = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int copies = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = ApplyNudge(project, nudgeflag, nudgewhat, nudgeunits, value, reverse, copies);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_Audio_Init() {
int buf_index = 4;
Audio_Init();
buf_index = 0;
return buf_index; 
}

int call_Audio_IsPreBuffer() {
int buf_index = 4;
int retval = Audio_IsPreBuffer();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_Audio_IsRunning() {
int buf_index = 4;
int retval = Audio_IsRunning();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_Audio_Quit() {
int buf_index = 4;
Audio_Quit();
buf_index = 0;
return buf_index; 
}

int call_AudioAccessorValidateState() {
int buf_index = 4;
AudioAccessor* accessor; memcpy(&accessor, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = AudioAccessorValidateState(accessor);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_BypassFxAllTracks() {
int buf_index = 4;
int bypass = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
BypassFxAllTracks(bypass);
buf_index = 0;
return buf_index; 
}

int call_ClearAllRecArmed() {
int buf_index = 4;
ClearAllRecArmed();
buf_index = 0;
return buf_index; 
}

int call_ClearConsole() {
int buf_index = 4;
ClearConsole();
buf_index = 0;
return buf_index; 
}

int call_ClearPeakCache() {
int buf_index = 4;
ClearPeakCache();
buf_index = 0;
return buf_index; 
}

int call_ColorFromNative() {
int buf_index = 4;
int col = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int rOut;
int gOut;
int bOut;
ColorFromNative(col, &rOut, &gOut, &bOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &rOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &gOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &bOut, 4); buf_index += 4;
return buf_index; 
}

int call_ColorToNative() {
int buf_index = 4;
int r = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int g = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int b = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = ColorToNative(r, g, b);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountEnvelopePoints() {
int buf_index = 4;
TrackEnvelope* envelope; memcpy(&envelope, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountEnvelopePoints(envelope);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountMediaItems() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountMediaItems(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountProjectMarkers() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int num_markersOut;
int num_regionsOut;
int retval = CountProjectMarkers(proj, &num_markersOut, &num_regionsOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &num_markersOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &num_regionsOut, 4); buf_index += 4;
return buf_index; 
}

int call_CountSelectedMediaItems() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountSelectedMediaItems(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountSelectedTracks() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountSelectedTracks(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountSelectedTracks2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool wantmaster = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = CountSelectedTracks2(proj, wantmaster);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTakeEnvelopes() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTakeEnvelopes(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTakes() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTakes(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTCPFXParms() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTCPFXParms(project, track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTempoTimeSigMarkers() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTempoTimeSigMarkers(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTrackEnvelopes() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTrackEnvelopes(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTrackMediaItems() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTrackMediaItems(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CountTracks() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CountTracks(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CreateTakeAudioAccessor() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
AudioAccessor* retval = CreateTakeAudioAccessor(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CreateTrackAudioAccessor() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
AudioAccessor* retval = CreateTrackAudioAccessor(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CreateTrackSend() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* desttrInOptional; memcpy(&desttrInOptional, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = CreateTrackSend(tr, desttrInOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CSurf_FlushUndo() {
int buf_index = 4;
bool force = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
CSurf_FlushUndo(force);
buf_index = 0;
return buf_index; 
}

int call_CSurf_GetTouchState() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int isPan = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = CSurf_GetTouchState(trackid, isPan);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_GoEnd() {
int buf_index = 4;
CSurf_GoEnd();
buf_index = 0;
return buf_index; 
}

int call_CSurf_GoStart() {
int buf_index = 4;
CSurf_GoStart();
buf_index = 0;
return buf_index; 
}

int call_CSurf_NumTracks() {
int buf_index = 4;
bool mcpView = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = CSurf_NumTracks(mcpView);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CSurf_OnArrow() {
int buf_index = 4;
int whichdir = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool wantzoom = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
CSurf_OnArrow(whichdir, wantzoom);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnFwd() {
int buf_index = 4;
int seekplay = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
CSurf_OnFwd(seekplay);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnFXChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int en = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = CSurf_OnFXChange(trackid, en);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnInputMonitorChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int monitor = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = CSurf_OnInputMonitorChange(trackid, monitor);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CSurf_OnInputMonitorChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int monitor = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool allowgang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = CSurf_OnInputMonitorChangeEx(trackid, monitor, allowgang);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_CSurf_OnMuteChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int mute = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = CSurf_OnMuteChange(trackid, mute);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnMuteChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int mute = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool allowgang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = CSurf_OnMuteChangeEx(trackid, mute, allowgang);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnPanChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnPanChange(trackid, pan, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnPanChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool allowGang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnPanChangeEx(trackid, pan, relative, allowGang);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnPause() {
int buf_index = 4;
CSurf_OnPause();
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnPlay() {
int buf_index = 4;
CSurf_OnPlay();
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnPlayRateChange() {
int buf_index = 4;
double playrate = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
CSurf_OnPlayRateChange(playrate);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnRecArmChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recarm = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = CSurf_OnRecArmChange(trackid, recarm);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnRecArmChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recarm = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool allowgang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = CSurf_OnRecArmChangeEx(trackid, recarm, allowgang);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnRecord() {
int buf_index = 4;
CSurf_OnRecord();
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnRecvPanChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recv_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnRecvPanChange(trackid, recv_index, pan, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnRecvVolumeChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recv_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double volume = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnRecvVolumeChange(trackid, recv_index, volume, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnRew() {
int buf_index = 4;
int seekplay = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
CSurf_OnRew(seekplay);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnRewFwd() {
int buf_index = 4;
int seekplay = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int dir = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
CSurf_OnRewFwd(seekplay, dir);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnScroll() {
int buf_index = 4;
int xdir = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int ydir = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
CSurf_OnScroll(xdir, ydir);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnSelectedChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int selected = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = CSurf_OnSelectedChange(trackid, selected);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnSendPanChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnSendPanChange(trackid, send_index, pan, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnSendVolumeChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double volume = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnSendVolumeChange(trackid, send_index, volume, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnSoloChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int solo = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = CSurf_OnSoloChange(trackid, solo);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnSoloChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
int solo = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool allowgang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = CSurf_OnSoloChangeEx(trackid, solo, allowgang);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_CSurf_OnStop() {
int buf_index = 4;
CSurf_OnStop();
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnTempoChange() {
int buf_index = 4;
double bpm = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
CSurf_OnTempoChange(bpm);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnTrackSelection() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_OnTrackSelection(trackid);
buf_index = 0;
return buf_index; 
}

int call_CSurf_OnVolumeChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double volume = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnVolumeChange(trackid, volume, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnVolumeChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double volume = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool allowGang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnVolumeChangeEx(trackid, volume, relative, allowGang);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnWidthChange() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double width = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnWidthChange(trackid, width, relative);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnWidthChangeEx() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double width = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool relative = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool allowGang = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = CSurf_OnWidthChangeEx(trackid, width, relative, allowGang);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_OnZoom() {
int buf_index = 4;
int xdir = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int ydir = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
CSurf_OnZoom(xdir, ydir);
buf_index = 0;
return buf_index; 
}

int call_CSurf_ResetAllCachedVolPanStates() {
int buf_index = 4;
CSurf_ResetAllCachedVolPanStates();
buf_index = 0;
return buf_index; 
}

int call_CSurf_ScrubAmt() {
int buf_index = 4;
double amt = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
CSurf_ScrubAmt(amt);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetAutoMode() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetAutoMode(mode, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetPlayState() {
int buf_index = 4;
bool play = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool pause = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool rec = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetPlayState(play, pause, rec, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetRepeatState() {
int buf_index = 4;
bool rep = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetRepeatState(rep, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetSurfaceMute() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool mute = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetSurfaceMute(trackid, mute, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetSurfacePan() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetSurfacePan(trackid, pan, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetSurfaceRecArm() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool recarm = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetSurfaceRecArm(trackid, recarm, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetSurfaceSelected() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetSurfaceSelected(trackid, selected, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetSurfaceSolo() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool solo = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetSurfaceSolo(trackid, solo, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetSurfaceVolume() {
int buf_index = 4;
MediaTrack* trackid; memcpy(&trackid, &sendrecvbuf[buf_index], 8); buf_index += 8;
double volume = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
IReaperControlSurface* ignoresurf; memcpy(&ignoresurf, &sendrecvbuf[buf_index], 8); buf_index += 8;
CSurf_SetSurfaceVolume(trackid, volume, ignoresurf);
buf_index = 0;
return buf_index; 
}

int call_CSurf_SetTrackListChange() {
int buf_index = 4;
CSurf_SetTrackListChange();
buf_index = 0;
return buf_index; 
}

int call_CSurf_TrackFromID() {
int buf_index = 4;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool mcpView = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
MediaTrack* retval = CSurf_TrackFromID(idx, mcpView);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_CSurf_TrackToID() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool mcpView = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = CSurf_TrackToID(track, mcpView);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_DB2SLIDER() {
int buf_index = 4;
double x = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = DB2SLIDER(x);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_DeleteEnvelopePointRange() {
int buf_index = 4;
TrackEnvelope* envelope; memcpy(&envelope, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time_start = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double time_end = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = DeleteEnvelopePointRange(envelope, time_start, time_end);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_DeleteExtState() {
int buf_index = 4;
const char* section = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(section);
const char* key = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(key);
bool persist = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
DeleteExtState(section, key, persist);
buf_index = 0;
return buf_index; 
}

int call_DeleteProjectMarker() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnindexnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = DeleteProjectMarker(proj, markrgnindexnumber, isrgn);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_DeleteProjectMarkerByIndex() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = DeleteProjectMarkerByIndex(proj, markrgnidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_DeleteTempoTimeSigMarker() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markerindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = DeleteTempoTimeSigMarker(project, markerindex);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_DeleteTrack() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
DeleteTrack(tr);
buf_index = 0;
return buf_index; 
}

int call_DeleteTrackMediaItem() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem* it; memcpy(&it, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = DeleteTrackMediaItem(tr, it);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_DestroyAudioAccessor() {
int buf_index = 4;
AudioAccessor* accessor; memcpy(&accessor, &sendrecvbuf[buf_index], 8); buf_index += 8;
DestroyAudioAccessor(accessor);
buf_index = 0;
return buf_index; 
}

int call_Dock_UpdateDockID() {
int buf_index = 4;
const char* ident_str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(ident_str);
int whichDock = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Dock_UpdateDockID(ident_str, whichDock);
buf_index = 0;
return buf_index; 
}

int call_DockIsChildOfDock() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isFloatingDockerOut;
int retval = DockIsChildOfDock(hwnd, &isFloatingDockerOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
sendrecvbuf[buf_index] = isFloatingDockerOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_DockWindowActivate() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
DockWindowActivate(hwnd);
buf_index = 0;
return buf_index; 
}

int call_DockWindowAdd() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int pos = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool allowShow = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
DockWindowAdd(hwnd, name, pos, allowShow);
buf_index = 0;
return buf_index; 
}

int call_DockWindowAddEx() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
const char* identstr = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(identstr);
bool allowShow = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
DockWindowAddEx(hwnd, name, identstr, allowShow);
buf_index = 0;
return buf_index; 
}

int call_DockWindowRefresh() {
int buf_index = 4;
DockWindowRefresh();
buf_index = 0;
return buf_index; 
}

int call_DockWindowRefreshForHWND() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
DockWindowRefreshForHWND(hwnd);
buf_index = 0;
return buf_index; 
}

int call_DockWindowRemove() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
DockWindowRemove(hwnd);
buf_index = 0;
return buf_index; 
}

int call_EditTempoTimeSigMarker() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markerindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = EditTempoTimeSigMarker(project, markerindex);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_EnumerateFiles() {
int buf_index = 4;
const char* path = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(path);
int fileindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = EnumerateFiles(path, fileindex);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_EnumerateSubdirectories() {
int buf_index = 4;
const char* path = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(path);
int subdirindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = EnumerateSubdirectories(path, subdirindex);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_EnumPitchShiftSubModes() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int submode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = EnumPitchShiftSubModes(mode, submode);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_EnumProjects() {
int buf_index = 4;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
ReaProject* retval = EnumProjects(idx, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_EnumProjExtState() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* extname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(extname);
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = EnumProjExtState(proj, extname, idx, charbuf0, 65535, charbuf1, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
memcpy(&sendrecvbuf[buf_index], charbuf1, 1 + strlen(charbuf1)); buf_index += 1 + strlen(charbuf1);
return buf_index; 
}

int call_EnumRegionRenderMatrix() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int regionindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int rendertrack = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaTrack* retval = EnumRegionRenderMatrix(proj, regionindex, rendertrack);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_EnumTrackMIDIProgramNames() {
int buf_index = 4;
int track = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int programNumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = EnumTrackMIDIProgramNames(track, programNumber, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_EnumTrackMIDIProgramNamesEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int programNumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = EnumTrackMIDIProgramNamesEx(proj, track, programNumber, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_Envelope_Evaluate() {
int buf_index = 4;
TrackEnvelope* envelope; memcpy(&envelope, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double samplerate = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int samplesRequested = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double valueOutOptional;
double dVdSOutOptional;
double ddVdSOutOptional;
double dddVdSOutOptional;
int retval = Envelope_Evaluate(envelope, time, samplerate, samplesRequested, &valueOutOptional, &dVdSOutOptional, &ddVdSOutOptional, &dddVdSOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &valueOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &dVdSOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &ddVdSOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &dddVdSOutOptional, 8); buf_index += 8;
return buf_index; 
}

int call_Envelope_FormatValue() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
double value = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
Envelope_FormatValue(env, value, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_Envelope_GetParentTake() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
int indexOutOptional;
int index2OutOptional;
MediaItem_Take* retval = Envelope_GetParentTake(env, &indexOutOptional, &index2OutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &indexOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &index2OutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_Envelope_GetParentTrack() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
int indexOutOptional;
int index2OutOptional;
MediaTrack* retval = Envelope_GetParentTrack(env, &indexOutOptional, &index2OutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &indexOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &index2OutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_Envelope_SortPoints() {
int buf_index = 4;
TrackEnvelope* envelope; memcpy(&envelope, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = Envelope_SortPoints(envelope);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_ExecProcess() {
int buf_index = 4;
const char* cmdline = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(cmdline);
int timeoutmsec = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = ExecProcess(cmdline, timeoutmsec);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_file_exists() {
int buf_index = 4;
const char* path = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(path);
bool retval = file_exists(path);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_FindTempoTimeSigMarker() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int retval = FindTempoTimeSigMarker(project, time);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_format_timestr() {
int buf_index = 4;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
format_timestr(tpos, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_format_timestr_len() {
int buf_index = 4;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double offset = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int modeoverride = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
format_timestr_len(tpos, charbuf0, 65535, offset, modeoverride);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_format_timestr_pos() {
int buf_index = 4;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int modeoverride = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
format_timestr_pos(tpos, charbuf0, 65535, modeoverride);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_get_ini_file() {
int buf_index = 4;
const char* retval = get_ini_file();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetActiveTake() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem_Take* retval = GetActiveTake(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetAllProjectPlayStates() {
int buf_index = 4;
ReaProject* ignoreProject; memcpy(&ignoreProject, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetAllProjectPlayStates(ignoreProject);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetAppVersion() {
int buf_index = 4;
const char* retval = GetAppVersion();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetAudioAccessorEndTime() {
int buf_index = 4;
AudioAccessor* accessor; memcpy(&accessor, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = GetAudioAccessorEndTime(accessor);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetAudioAccessorHash() {
int buf_index = 4;
AudioAccessor* accessor; memcpy(&accessor, &sendrecvbuf[buf_index], 8); buf_index += 8;
GetAudioAccessorHash(accessor, charbuf0);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetAudioAccessorStartTime() {
int buf_index = 4;
AudioAccessor* accessor; memcpy(&accessor, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = GetAudioAccessorStartTime(accessor);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetConfigWantsDock() {
int buf_index = 4;
const char* ident_str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(ident_str);
int retval = GetConfigWantsDock(ident_str);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetCurrentProjectInLoadSave() {
int buf_index = 4;
ReaProject* retval = GetCurrentProjectInLoadSave();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetCursorContext() {
int buf_index = 4;
int retval = GetCursorContext();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetCursorContext2() {
int buf_index = 4;
bool want_last_valid = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = GetCursorContext2(want_last_valid);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetCursorPosition() {
int buf_index = 4;
double retval = GetCursorPosition();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetCursorPositionEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = GetCursorPositionEx(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetDisplayedMediaItemColor() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetDisplayedMediaItemColor(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetDisplayedMediaItemColor2() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetDisplayedMediaItemColor2(item, take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetEnvelopeName() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = GetEnvelopeName(env, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetEnvelopePoint() {
int buf_index = 4;
TrackEnvelope* envelope; memcpy(&envelope, &sendrecvbuf[buf_index], 8); buf_index += 8;
int ptidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double timeOutOptional;
double valueOutOptional;
int shapeOutOptional;
double tensionOutOptional;
bool selectedOutOptional;
bool retval = GetEnvelopePoint(envelope, ptidx, &timeOutOptional, &valueOutOptional, &shapeOutOptional, &tensionOutOptional, &selectedOutOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &timeOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &valueOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &shapeOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &tensionOutOptional, 8); buf_index += 8;
sendrecvbuf[buf_index] = selectedOutOptional ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_GetEnvelopePointByTime() {
int buf_index = 4;
TrackEnvelope* envelope; memcpy(&envelope, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int retval = GetEnvelopePointByTime(envelope, time);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetEnvelopeScalingMode() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetEnvelopeScalingMode(env);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetEnvelopeStateChunk() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isundoOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetEnvelopeStateChunk(env, charbuf0, 65535, isundoOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetExePath() {
int buf_index = 4;
const char* retval = GetExePath();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetExtState() {
int buf_index = 4;
const char* section = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(section);
const char* key = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(key);
const char* retval = GetExtState(section, key);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetFocusedFX() {
int buf_index = 4;
int tracknumberOut;
int itemnumberOut;
int fxnumberOut;
int retval = GetFocusedFX(&tracknumberOut, &itemnumberOut, &fxnumberOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &tracknumberOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &itemnumberOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &fxnumberOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetFreeDiskSpaceForRecordPath() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int pathidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GetFreeDiskSpaceForRecordPath(proj, pathidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetFXEnvelope() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fxindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int parameterindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool create = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TrackEnvelope* retval = GetFXEnvelope(track, fxindex, parameterindex, create);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetGlobalAutomationOverride() {
int buf_index = 4;
int retval = GetGlobalAutomationOverride();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetHZoomLevel() {
int buf_index = 4;
double retval = GetHZoomLevel();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetInputChannelName() {
int buf_index = 4;
int channelIndex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = GetInputChannelName(channelIndex);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetInputOutputLatency() {
int buf_index = 4;
int inputlatencyOut;
int outputLatencyOut;
GetInputOutputLatency(&inputlatencyOut, &outputLatencyOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &inputlatencyOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &outputLatencyOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetItemProjectContext() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
ReaProject* retval = GetItemProjectContext(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetItemStateChunk() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isundoOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetItemStateChunk(item, charbuf0, 65535, isundoOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetLastColorThemeFile() {
int buf_index = 4;
const char* retval = GetLastColorThemeFile();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetLastMarkerAndCurRegion() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int markeridxOut;
int regionidxOut;
GetLastMarkerAndCurRegion(proj, time, &markeridxOut, &regionidxOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &markeridxOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &regionidxOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetLastTouchedFX() {
int buf_index = 4;
int tracknumberOut;
int fxnumberOut;
int paramnumberOut;
bool retval = GetLastTouchedFX(&tracknumberOut, &fxnumberOut, &paramnumberOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &tracknumberOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &fxnumberOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &paramnumberOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetLastTouchedTrack() {
int buf_index = 4;
MediaTrack* retval = GetLastTouchedTrack();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMainHwnd() {
int buf_index = 4;
HWND retval = GetMainHwnd();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMasterMuteSoloFlags() {
int buf_index = 4;
int retval = GetMasterMuteSoloFlags();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMasterTrack() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* retval = GetMasterTrack(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMasterTrackVisibility() {
int buf_index = 4;
int retval = GetMasterTrackVisibility();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMaxMidiInputs() {
int buf_index = 4;
int retval = GetMaxMidiInputs();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMaxMidiOutputs() {
int buf_index = 4;
int retval = GetMaxMidiOutputs();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMediaItem() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int itemidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaItem* retval = GetMediaItem(proj, itemidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItem_Track() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* retval = GetMediaItem_Track(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemInfo_Value() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double retval = GetMediaItemInfo_Value(item, parmname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemNumTakes() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetMediaItemNumTakes(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMediaItemTake() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
int tk = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaItem_Take* retval = GetMediaItemTake(item, tk);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemTake_Item() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem* retval = GetMediaItemTake_Item(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemTake_Source() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
PCM_source* retval = GetMediaItemTake_Source(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemTake_Track() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* retval = GetMediaItemTake_Track(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemTakeInfo_Value() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double retval = GetMediaItemTakeInfo_Value(take, parmname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaItemTrack() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* retval = GetMediaItemTrack(item);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaSourceFileName() {
int buf_index = 4;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
GetMediaSourceFileName(source, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetMediaSourceLength() {
int buf_index = 4;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool lengthIsQNOut;
double retval = GetMediaSourceLength(source, &lengthIsQNOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
sendrecvbuf[buf_index] = lengthIsQNOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_GetMediaSourceNumChannels() {
int buf_index = 4;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetMediaSourceNumChannels(source);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMediaSourceParent() {
int buf_index = 4;
PCM_source* src; memcpy(&src, &sendrecvbuf[buf_index], 8); buf_index += 8;
PCM_source* retval = GetMediaSourceParent(src);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMediaSourceSampleRate() {
int buf_index = 4;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetMediaSourceSampleRate(source);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetMediaSourceType() {
int buf_index = 4;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
GetMediaSourceType(source, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetMediaTrackInfo_Value() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double retval = GetMediaTrackInfo_Value(tr, parmname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMIDIInputName() {
int buf_index = 4;
int dev = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = GetMIDIInputName(dev, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetMIDIOutputName() {
int buf_index = 4;
int dev = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = GetMIDIOutputName(dev, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetMixerScroll() {
int buf_index = 4;
MediaTrack* retval = GetMixerScroll();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetMouseModifier() {
int buf_index = 4;
const char* context = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(context);
int modifier_flag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
GetMouseModifier(context, modifier_flag, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetMousePosition() {
int buf_index = 4;
int xOut;
int yOut;
GetMousePosition(&xOut, &yOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &xOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &yOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetNumAudioInputs() {
int buf_index = 4;
int retval = GetNumAudioInputs();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetNumAudioOutputs() {
int buf_index = 4;
int retval = GetNumAudioOutputs();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetNumMIDIInputs() {
int buf_index = 4;
int retval = GetNumMIDIInputs();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetNumMIDIOutputs() {
int buf_index = 4;
int retval = GetNumMIDIOutputs();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetNumTracks() {
int buf_index = 4;
int retval = GetNumTracks();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetOS() {
int buf_index = 4;
const char* retval = GetOS();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetOutputChannelName() {
int buf_index = 4;
int channelIndex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = GetOutputChannelName(channelIndex);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetOutputLatency() {
int buf_index = 4;
double retval = GetOutputLatency();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetParentTrack() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* retval = GetParentTrack(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetPeakFileName() {
int buf_index = 4;
const char* fn = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fn);
GetPeakFileName(fn, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetPeakFileNameEx() {
int buf_index = 4;
const char* fn = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fn);
bool forWrite = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GetPeakFileNameEx(fn, charbuf0, 65535, forWrite);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetPeakFileNameEx2() {
int buf_index = 4;
const char* fn = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fn);
bool forWrite = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
const char* peaksfileextension = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(peaksfileextension);
GetPeakFileNameEx2(fn, charbuf0, 65535, forWrite, peaksfileextension);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetPlayPosition() {
int buf_index = 4;
double retval = GetPlayPosition();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetPlayPosition2() {
int buf_index = 4;
double retval = GetPlayPosition2();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetPlayPosition2Ex() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = GetPlayPosition2Ex(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetPlayPositionEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = GetPlayPositionEx(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetPlayState() {
int buf_index = 4;
int retval = GetPlayState();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetPlayStateEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetPlayStateEx(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetProjectLength() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = GetProjectLength(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetProjectName() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
GetProjectName(proj, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetProjectPath() {
int buf_index = 4;
GetProjectPath(charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetProjectPathEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
GetProjectPathEx(proj, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetProjectStateChangeCount() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetProjectStateChangeCount(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetProjectTimeOffset() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool rndframe = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = GetProjectTimeOffset(proj, rndframe);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetProjectTimeSignature() {
int buf_index = 4;
double bpmOut;
double bpiOut;
GetProjectTimeSignature(&bpmOut, &bpiOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &bpmOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &bpiOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetProjectTimeSignature2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double bpmOut;
double bpiOut;
GetProjectTimeSignature2(proj, &bpmOut, &bpiOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &bpmOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &bpiOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetProjExtState() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* extname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(extname);
const char* key = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(key);
int retval = GetProjExtState(proj, extname, key, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetResourcePath() {
int buf_index = 4;
const char* retval = GetResourcePath();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetSelectedEnvelope() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
TrackEnvelope* retval = GetSelectedEnvelope(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetSelectedMediaItem() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int selitem = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaItem* retval = GetSelectedMediaItem(proj, selitem);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetSelectedTrack() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int seltrackidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaTrack* retval = GetSelectedTrack(proj, seltrackidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetSelectedTrack2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int seltrackidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool wantmaster = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
MediaTrack* retval = GetSelectedTrack2(proj, seltrackidx, wantmaster);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetSelectedTrackEnvelope() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
TrackEnvelope* retval = GetSelectedTrackEnvelope(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetSet_ArrangeView2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isSet = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int screen_x_start = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int screen_x_end = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double start_timeOut;
double end_timeOut;
GetSet_ArrangeView2(proj, isSet, screen_x_start, screen_x_end, &start_timeOut, &end_timeOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &start_timeOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &end_timeOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetSet_LoopTimeRange() {
int buf_index = 4;
bool isSet = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool isLoop = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double startOut;
double endOut;
bool allowautoseek = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GetSet_LoopTimeRange(isSet, isLoop, &startOut, &endOut, allowautoseek);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &startOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &endOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetSet_LoopTimeRange2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isSet = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool isLoop = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double startOut;
double endOut;
bool allowautoseek = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GetSet_LoopTimeRange2(proj, isSet, isLoop, &startOut, &endOut, allowautoseek);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &startOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &endOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetSetEnvelopeState() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = GetSetEnvelopeState(env, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetEnvelopeState2() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isundo = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetSetEnvelopeState2(env, charbuf0, 65535, isundo);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetItemState() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = GetSetItemState(item, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetItemState2() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isundo = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetSetItemState2(item, charbuf0, 65535, isundo);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetMediaItemTakeInfo_String() {
int buf_index = 4;
MediaItem_Take* tk; memcpy(&tk, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
bool setnewvalue = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetSetMediaItemTakeInfo_String(tk, parmname, charbuf0, setnewvalue);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetMediaTrackInfo_String() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
bool setnewvalue = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetSetMediaTrackInfo_String(tr, parmname, charbuf0, setnewvalue);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetProjectAuthor() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool set = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GetSetProjectAuthor(proj, set, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetProjectNotes() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool set = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GetSetProjectNotes(proj, set, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetRepeat() {
int buf_index = 4;
int val = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GetSetRepeat(val);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetSetRepeatEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int val = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GetSetRepeatEx(proj, val);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetSetTrackState() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = GetSetTrackState(track, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSetTrackState2() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isundo = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetSetTrackState2(track, charbuf0, 65535, isundo);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetSubProjectFromSource() {
int buf_index = 4;
PCM_source* src; memcpy(&src, &sendrecvbuf[buf_index], 8); buf_index += 8;
ReaProject* retval = GetSubProjectFromSource(src);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTake() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
int takeidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaItem_Take* retval = GetTake(item, takeidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTakeEnvelope() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int envidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TrackEnvelope* retval = GetTakeEnvelope(take, envidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTakeEnvelopeByName() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* envname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(envname);
TrackEnvelope* retval = GetTakeEnvelopeByName(take, envname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTakeName() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* retval = GetTakeName(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetTakeNumStretchMarkers() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetTakeNumStretchMarkers(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTakeStretchMarker() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double posOut;
double srcposOutOptional;
int retval = GetTakeStretchMarker(take, idx, &posOut, &srcposOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &posOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &srcposOutOptional, 8); buf_index += 8;
return buf_index; 
}

int call_GetTakeStretchMarkerSlope() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double retval = GetTakeStretchMarkerSlope(take, idx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTCPFXParm() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int fxindexOut;
int parmidxOut;
bool retval = GetTCPFXParm(project, track, index, &fxindexOut, &parmidxOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &fxindexOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &parmidxOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetTempoMatchPlayRate() {
int buf_index = 4;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
double srcscale = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double position = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double mult = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rateOut;
double targetlenOut;
bool retval = GetTempoMatchPlayRate(source, srcscale, position, mult, &rateOut, &targetlenOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &rateOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &targetlenOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetTempoTimeSigMarker() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int ptidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double timeposOut;
int measureposOut;
double beatposOut;
double bpmOut;
int timesig_numOut;
int timesig_denomOut;
bool lineartempoOut;
bool retval = GetTempoTimeSigMarker(proj, ptidx, &timeposOut, &measureposOut, &beatposOut, &bpmOut, &timesig_numOut, &timesig_denomOut, &lineartempoOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &timeposOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &measureposOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &beatposOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &bpmOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &timesig_numOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &timesig_denomOut, 4); buf_index += 4;
sendrecvbuf[buf_index] = lineartempoOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_GetToggleCommandState() {
int buf_index = 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GetToggleCommandState(command_id);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetToggleCommandStateEx() {
int buf_index = 4;
int section_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GetToggleCommandStateEx(section_id, command_id);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTooltipWindow() {
int buf_index = 4;
HWND retval = GetTooltipWindow();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrack() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int trackidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaTrack* retval = GetTrack(proj, trackidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackAutomationMode() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetTrackAutomationMode(tr);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackColor() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetTrackColor(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackDepth() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetTrackDepth(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackEnvelope() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int envidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TrackEnvelope* retval = GetTrackEnvelope(track, envidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackEnvelopeByChunkName() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* cfgchunkname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(cfgchunkname);
TrackEnvelope* retval = GetTrackEnvelopeByChunkName(tr, cfgchunkname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackEnvelopeByName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* envname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(envname);
TrackEnvelope* retval = GetTrackEnvelopeByName(track, envname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackMediaItem() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int itemidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaItem* retval = GetTrackMediaItem(tr, itemidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackMIDINoteName() {
int buf_index = 4;
int track = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int pitch = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int chan = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = GetTrackMIDINoteName(track, pitch, chan);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetTrackMIDINoteNameEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int pitch = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int chan = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = GetTrackMIDINoteNameEx(proj, track, pitch, chan);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_GetTrackMIDINoteRange() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int note_loOut;
int note_hiOut;
GetTrackMIDINoteRange(proj, track, &note_loOut, &note_hiOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &note_loOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &note_hiOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = GetTrackName(track, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetTrackNumMediaItems() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = GetTrackNumMediaItems(tr);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackNumSends() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int category = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GetTrackNumSends(tr, category);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackReceiveName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recv_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = GetTrackReceiveName(track, recv_index, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetTrackReceiveUIMute() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recv_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool muteOut;
bool retval = GetTrackReceiveUIMute(track, recv_index, &muteOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = muteOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_GetTrackReceiveUIVolPan() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int recv_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double volumeOut;
double panOut;
bool retval = GetTrackReceiveUIVolPan(track, recv_index, &volumeOut, &panOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &volumeOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &panOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackSendInfo_Value() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int category = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int sendidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double retval = GetTrackSendInfo_Value(tr, category, sendidx, parmname);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackSendName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = GetTrackSendName(track, send_index, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetTrackSendUIMute() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool muteOut;
bool retval = GetTrackSendUIMute(track, send_index, &muteOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = muteOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_GetTrackSendUIVolPan() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double volumeOut;
double panOut;
bool retval = GetTrackSendUIVolPan(track, send_index, &volumeOut, &panOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &volumeOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &panOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetTrackState() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int flagsOut;
const char* retval = GetTrackState(track, &flagsOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
memcpy(&sendrecvbuf[buf_index], &flagsOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackStateChunk() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool isundoOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = GetTrackStateChunk(track, charbuf0, 65535, isundoOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetTrackUIMute() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool muteOut;
bool retval = GetTrackUIMute(track, &muteOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = muteOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_GetTrackUIPan() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
double pan1Out;
double pan2Out;
int panmodeOut;
bool retval = GetTrackUIPan(track, &pan1Out, &pan2Out, &panmodeOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &pan1Out, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &pan2Out, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &panmodeOut, 4); buf_index += 4;
return buf_index; 
}

int call_GetTrackUIVolPan() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
double volumeOut;
double panOut;
bool retval = GetTrackUIVolPan(track, &volumeOut, &panOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &volumeOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &panOut, 8); buf_index += 8;
return buf_index; 
}

int call_GetUserFileNameForRead() {
int buf_index = 4;
const char* title = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(title);
const char* defext = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(defext);
bool retval = GetUserFileNameForRead(charbuf0, title, defext);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GetUserInputs() {
int buf_index = 4;
const char* title = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(title);
int num_inputs = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* captions_csv = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(captions_csv);
bool retval = GetUserInputs(title, num_inputs, captions_csv, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_GoToMarker() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int marker_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool use_timeline_order = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GoToMarker(proj, marker_index, use_timeline_order);
buf_index = 0;
return buf_index; 
}

int call_GoToRegion() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int region_index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool use_timeline_order = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
GoToRegion(proj, region_index, use_timeline_order);
buf_index = 0;
return buf_index; 
}

int call_GR_SelectColor() {
int buf_index = 4;
HWND hwnd; memcpy(&hwnd, &sendrecvbuf[buf_index], 8); buf_index += 8;
int colorOut;
int retval = GR_SelectColor(hwnd, &colorOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &colorOut, 4); buf_index += 4;
return buf_index; 
}

int call_GSC_mainwnd() {
int buf_index = 4;
int t = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = GSC_mainwnd(t);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_HasExtState() {
int buf_index = 4;
const char* section = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(section);
const char* key = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(key);
bool retval = HasExtState(section, key);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_HasTrackMIDIPrograms() {
int buf_index = 4;
int track = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = HasTrackMIDIPrograms(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_HasTrackMIDIProgramsEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* retval = HasTrackMIDIProgramsEx(proj, track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_Help_Set() {
int buf_index = 4;
const char* helpstring = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(helpstring);
bool is_temporary_help = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
Help_Set(helpstring, is_temporary_help);
buf_index = 0;
return buf_index; 
}

int call_image_resolve_fn() {
int buf_index = 4;
const char* in = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(in);
image_resolve_fn(in, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_InsertMedia() {
int buf_index = 4;
const char* file = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(file);
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = InsertMedia(file, mode);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_InsertMediaSection() {
int buf_index = 4;
const char* file = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(file);
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double startpct = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double endpct = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double pitchshift = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int retval = InsertMediaSection(file, mode, startpct, endpct, pitchshift);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_InsertTrackAtIndex() {
int buf_index = 4;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool wantDefaults = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
InsertTrackAtIndex(idx, wantDefaults);
buf_index = 0;
return buf_index; 
}

int call_IsMediaExtension() {
int buf_index = 4;
const char* ext = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(ext);
bool wantOthers = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = IsMediaExtension(ext, wantOthers);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_IsMediaItemSelected() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = IsMediaItemSelected(item);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_IsProjectDirty() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = IsProjectDirty(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_IsTrackSelected() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = IsTrackSelected(track);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_IsTrackVisible() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool mixer = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = IsTrackVisible(track, mixer);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_LICE_ClipLine() {
int buf_index = 4;
int pX1Out;
int pY1Out;
int pX2Out;
int pY2Out;
int xLo = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int yLo = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int xHi = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int yHi = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = LICE_ClipLine(&pX1Out, &pY1Out, &pX2Out, &pY2Out, xLo, yLo, xHi, yHi);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &pX1Out, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &pY1Out, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &pX2Out, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &pY2Out, 4); buf_index += 4;
return buf_index; 
}

int call_Loop_OnArrow() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
int direction = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = Loop_OnArrow(project, direction);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_Main_OnCommand() {
int buf_index = 4;
int command = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int flag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Main_OnCommand(command, flag);
buf_index = 0;
return buf_index; 
}

int call_Main_OnCommandEx() {
int buf_index = 4;
int command = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int flag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
Main_OnCommandEx(command, flag, proj);
buf_index = 0;
return buf_index; 
}

int call_Main_openProject() {
int buf_index = 4;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
Main_openProject(name);
buf_index = 0;
return buf_index; 
}

int call_Main_SaveProject() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool forceSaveAsInOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
Main_SaveProject(proj, forceSaveAsInOptional);
buf_index = 0;
return buf_index; 
}

int call_Main_UpdateLoopInfo() {
int buf_index = 4;
int ignoremask = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Main_UpdateLoopInfo(ignoremask);
buf_index = 0;
return buf_index; 
}

int call_MarkProjectDirty() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MarkProjectDirty(proj);
buf_index = 0;
return buf_index; 
}

int call_MarkTrackItemsDirty() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MarkTrackItemsDirty(track, item);
buf_index = 0;
return buf_index; 
}

int call_Master_GetPlayRate() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = Master_GetPlayRate(project);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_Master_GetPlayRateAtTime() {
int buf_index = 4;
double time_s = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double retval = Master_GetPlayRateAtTime(time_s, proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_Master_GetTempo() {
int buf_index = 4;
double retval = Master_GetTempo();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_Master_NormalizePlayRate() {
int buf_index = 4;
double playrate = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool isnormalized = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = Master_NormalizePlayRate(playrate, isnormalized);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_Master_NormalizeTempo() {
int buf_index = 4;
double bpm = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool isnormalized = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = Master_NormalizeTempo(bpm, isnormalized);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MB() {
int buf_index = 4;
const char* msg = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(msg);
const char* title = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(title);
int type = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = MB(msg, title, type);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MediaItemDescendsFromTrack() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = MediaItemDescendsFromTrack(item, track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_CountEvts() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int notecntOut;
int ccevtcntOut;
int textsyxevtcntOut;
int retval = MIDI_CountEvts(take, &notecntOut, &ccevtcntOut, &textsyxevtcntOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &notecntOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &ccevtcntOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &textsyxevtcntOut, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_DeleteCC() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int ccidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_DeleteCC(take, ccidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_DeleteEvt() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int evtidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_DeleteEvt(take, evtidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_DeleteNote() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int noteidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_DeleteNote(take, noteidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_DeleteTextSysexEvt() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int textsyxevtidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_DeleteTextSysexEvt(take, textsyxevtidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_EnumSelCC() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int ccidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = MIDI_EnumSelCC(take, ccidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_EnumSelEvts() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int evtidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = MIDI_EnumSelEvts(take, evtidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_EnumSelNotes() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int noteidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = MIDI_EnumSelNotes(take, noteidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_EnumSelTextSysexEvts() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int textsyxidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = MIDI_EnumSelTextSysexEvts(take, textsyxidx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_GetCC() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int ccidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool selectedOut;
bool mutedOut;
double ppqposOut;
int chanmsgOut;
int chanOut;
int msg2Out;
int msg3Out;
bool retval = MIDI_GetCC(take, ccidx, &selectedOut, &mutedOut, &ppqposOut, &chanmsgOut, &chanOut, &msg2Out, &msg3Out);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = selectedOut ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = mutedOut ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &ppqposOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &chanmsgOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &chanOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &msg2Out, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &msg3Out, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_GetGrid() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double swingOutOptional;
double noteLenOutOptional;
double retval = MIDI_GetGrid(take, &swingOutOptional, &noteLenOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &swingOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &noteLenOutOptional, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetHash() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool notesonly = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = MIDI_GetHash(take, notesonly, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_MIDI_GetNote() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int noteidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool selectedOut;
bool mutedOut;
double startppqposOut;
double endppqposOut;
int chanOut;
int pitchOut;
int velOut;
bool retval = MIDI_GetNote(take, noteidx, &selectedOut, &mutedOut, &startppqposOut, &endppqposOut, &chanOut, &pitchOut, &velOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = selectedOut ? 1 : 0; buf_index += 1;
sendrecvbuf[buf_index] = mutedOut ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &startppqposOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &endppqposOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &chanOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &pitchOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &velOut, 4); buf_index += 4;
return buf_index; 
}

int call_MIDI_GetPPQPos_EndOfMeasure() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = MIDI_GetPPQPos_EndOfMeasure(take, ppqpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetPPQPos_StartOfMeasure() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = MIDI_GetPPQPos_StartOfMeasure(take, ppqpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetPPQPosFromProjQN() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double projqn = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = MIDI_GetPPQPosFromProjQN(take, projqn);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetPPQPosFromProjTime() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double projtime = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = MIDI_GetPPQPosFromProjTime(take, projtime);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetProjQNFromPPQPos() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = MIDI_GetProjQNFromPPQPos(take, ppqpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetProjTimeFromPPQPos() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = MIDI_GetProjTimeFromPPQPos(take, ppqpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDI_GetScale() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int rootOut;
int scaleOut;
bool retval = MIDI_GetScale(take, &rootOut, &scaleOut, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &rootOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &scaleOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_MIDI_GetTrackHash() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool notesonly = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = MIDI_GetTrackHash(track, notesonly, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_MIDI_InsertCC() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool muted = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int chanmsg = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int chan = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int msg2 = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int msg3 = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_InsertCC(take, selected, muted, ppqpos, chanmsg, chan, msg2, msg3);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_InsertEvt() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool muted = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* bytestr = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(bytestr);
int bytestr_sz = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_InsertEvt(take, selected, muted, ppqpos, bytestr, bytestr_sz);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_InsertTextSysexEvt() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool muted = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double ppqpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int type = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* bytestr = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(bytestr);
int bytestr_sz = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_InsertTextSysexEvt(take, selected, muted, ppqpos, type, bytestr, bytestr_sz);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_midi_reinit() {
int buf_index = 4;
midi_reinit();
buf_index = 0;
return buf_index; 
}

int call_MIDI_SelectAll() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool select = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
MIDI_SelectAll(take, select);
buf_index = 0;
return buf_index; 
}

int call_MIDI_SetAllEvts() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* buf = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(buf);
int buf_sz = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDI_SetAllEvts(take, buf, buf_sz);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_SetItemExtents() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
double startQN = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double endQN = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = MIDI_SetItemExtents(item, startQN, endQN);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDI_Sort() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
MIDI_Sort(take);
buf_index = 0;
return buf_index; 
}

int call_MIDIEditor_GetActive() {
int buf_index = 4;
HWND retval = MIDIEditor_GetActive();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDIEditor_GetMode() {
int buf_index = 4;
HWND midieditor; memcpy(&midieditor, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = MIDIEditor_GetMode(midieditor);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDIEditor_GetSetting_int() {
int buf_index = 4;
HWND midieditor; memcpy(&midieditor, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* setting_desc = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(setting_desc);
int retval = MIDIEditor_GetSetting_int(midieditor, setting_desc);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_MIDIEditor_GetSetting_str() {
int buf_index = 4;
HWND midieditor; memcpy(&midieditor, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* setting_desc = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(setting_desc);
bool retval = MIDIEditor_GetSetting_str(midieditor, setting_desc, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_MIDIEditor_GetTake() {
int buf_index = 4;
HWND midieditor; memcpy(&midieditor, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaItem_Take* retval = MIDIEditor_GetTake(midieditor);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_MIDIEditor_LastFocused_OnCommand() {
int buf_index = 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool islistviewcommand = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = MIDIEditor_LastFocused_OnCommand(command_id, islistviewcommand);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MIDIEditor_OnCommand() {
int buf_index = 4;
HWND midieditor; memcpy(&midieditor, &sendrecvbuf[buf_index], 8); buf_index += 8;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = MIDIEditor_OnCommand(midieditor, command_id);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_mkpanstr() {
int buf_index = 4;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
mkpanstr(charbuf0, pan);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_mkvolpanstr() {
int buf_index = 4;
double vol = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
mkvolpanstr(charbuf0, vol, pan);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_mkvolstr() {
int buf_index = 4;
double vol = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
mkvolstr(charbuf0, vol);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_MoveEditCursor() {
int buf_index = 4;
double adjamt = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool dosel = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
MoveEditCursor(adjamt, dosel);
buf_index = 0;
return buf_index; 
}

int call_MoveMediaItemToTrack() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* desttr; memcpy(&desttr, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = MoveMediaItemToTrack(item, desttr);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_MuteAllTracks() {
int buf_index = 4;
bool mute = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
MuteAllTracks(mute);
buf_index = 0;
return buf_index; 
}

int call_NamedCommandLookup() {
int buf_index = 4;
const char* command_name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(command_name);
int retval = NamedCommandLookup(command_name);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_OnPauseButton() {
int buf_index = 4;
OnPauseButton();
buf_index = 0;
return buf_index; 
}

int call_OnPauseButtonEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
OnPauseButtonEx(proj);
buf_index = 0;
return buf_index; 
}

int call_OnPlayButton() {
int buf_index = 4;
OnPlayButton();
buf_index = 0;
return buf_index; 
}

int call_OnPlayButtonEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
OnPlayButtonEx(proj);
buf_index = 0;
return buf_index; 
}

int call_OnStopButton() {
int buf_index = 4;
OnStopButton();
buf_index = 0;
return buf_index; 
}

int call_OnStopButtonEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
OnStopButtonEx(proj);
buf_index = 0;
return buf_index; 
}

int call_OpenColorThemeFile() {
int buf_index = 4;
const char* fn = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fn);
bool retval = OpenColorThemeFile(fn);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_OpenMediaExplorer() {
int buf_index = 4;
const char* mediafn = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(mediafn);
bool play = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
HWND retval = OpenMediaExplorer(mediafn, play);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_parse_timestr() {
int buf_index = 4;
const char* buf = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(buf);
double retval = parse_timestr(buf);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_parse_timestr_len() {
int buf_index = 4;
const char* buf = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(buf);
double offset = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int modeoverride = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double retval = parse_timestr_len(buf, offset, modeoverride);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_parse_timestr_pos() {
int buf_index = 4;
const char* buf = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(buf);
int modeoverride = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double retval = parse_timestr_pos(buf, modeoverride);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_parsepanstr() {
int buf_index = 4;
const char* str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(str);
double retval = parsepanstr(str);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_PCM_Sink_GetExtension() {
int buf_index = 4;
const char* data = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(data);
int data_sz = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = PCM_Sink_GetExtension(data, data_sz);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_PCM_Sink_ShowConfig() {
int buf_index = 4;
const char* cfg = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(cfg);
int cfg_sz = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
HWND hwndParent; memcpy(&hwndParent, &sendrecvbuf[buf_index], 8); buf_index += 8;
HWND retval = PCM_Sink_ShowConfig(cfg, cfg_sz, hwndParent);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_PCM_Source_CreateFromFile() {
int buf_index = 4;
const char* filename = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(filename);
PCM_source* retval = PCM_Source_CreateFromFile(filename);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_PCM_Source_CreateFromFileEx() {
int buf_index = 4;
const char* filename = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(filename);
bool forcenoMidiImp = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
PCM_source* retval = PCM_Source_CreateFromFileEx(filename, forcenoMidiImp);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_PCM_Source_CreateFromType() {
int buf_index = 4;
const char* sourcetype = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(sourcetype);
PCM_source* retval = PCM_Source_CreateFromType(sourcetype);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_PCM_Source_Destroy() {
int buf_index = 4;
PCM_source* src; memcpy(&src, &sendrecvbuf[buf_index], 8); buf_index += 8;
PCM_Source_Destroy(src);
buf_index = 0;
return buf_index; 
}

int call_PCM_Source_GetSectionInfo() {
int buf_index = 4;
PCM_source* src; memcpy(&src, &sendrecvbuf[buf_index], 8); buf_index += 8;
double offsOut;
double lenOut;
bool revOut;
bool retval = PCM_Source_GetSectionInfo(src, &offsOut, &lenOut, &revOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &offsOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &lenOut, 8); buf_index += 8;
sendrecvbuf[buf_index] = revOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_PluginWantsAlwaysRunFx() {
int buf_index = 4;
int amt = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
PluginWantsAlwaysRunFx(amt);
buf_index = 0;
return buf_index; 
}

int call_PreventUIRefresh() {
int buf_index = 4;
int prevent_count = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
PreventUIRefresh(prevent_count);
buf_index = 0;
return buf_index; 
}

int call_ReaScriptError() {
int buf_index = 4;
const char* errmsg = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(errmsg);
ReaScriptError(errmsg);
buf_index = 0;
return buf_index; 
}

int call_RefreshToolbar() {
int buf_index = 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
RefreshToolbar(command_id);
buf_index = 0;
return buf_index; 
}

int call_RefreshToolbar2() {
int buf_index = 4;
int section_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
RefreshToolbar2(section_id, command_id);
buf_index = 0;
return buf_index; 
}

int call_relative_fn() {
int buf_index = 4;
const char* in = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(in);
relative_fn(in, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_RemoveTrackSend() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int category = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int sendidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = RemoveTrackSend(tr, category, sendidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_RenderFileSection() {
int buf_index = 4;
const char* source_filename = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(source_filename);
const char* target_filename = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(target_filename);
double start_percent = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double end_percent = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double playrate = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = RenderFileSection(source_filename, target_filename, start_percent, end_percent, playrate);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_Resample_EnumModes() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = Resample_EnumModes(mode);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_resolve_fn() {
int buf_index = 4;
const char* in = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(in);
resolve_fn(in, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_resolve_fn2() {
int buf_index = 4;
const char* in = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(in);
const char* checkSubDirOptional = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(checkSubDirOptional);
resolve_fn2(in, charbuf0, 65535, checkSubDirOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_ReverseNamedCommandLookup() {
int buf_index = 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* retval = ReverseNamedCommandLookup(command_id);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_ScaleFromEnvelopeMode() {
int buf_index = 4;
int scaling_mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = ScaleFromEnvelopeMode(scaling_mode, val);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_ScaleToEnvelopeMode() {
int buf_index = 4;
int scaling_mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = ScaleToEnvelopeMode(scaling_mode, val);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_SelectAllMediaItems() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SelectAllMediaItems(proj, selected);
buf_index = 0;
return buf_index; 
}

int call_SelectProjectInstance() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
SelectProjectInstance(proj);
buf_index = 0;
return buf_index; 
}

int call_SetActiveTake() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
SetActiveTake(take);
buf_index = 0;
return buf_index; 
}

int call_SetAutomationMode() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool onlySel = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetAutomationMode(mode, onlySel);
buf_index = 0;
return buf_index; 
}

int call_SetCurrentBPM() {
int buf_index = 4;
ReaProject* __proj; memcpy(&__proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double bpm = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool wantUndo = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetCurrentBPM(__proj, bpm, wantUndo);
buf_index = 0;
return buf_index; 
}

int call_SetCursorContext() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TrackEnvelope* envInOptional; memcpy(&envInOptional, &sendrecvbuf[buf_index], 8); buf_index += 8;
SetCursorContext(mode, envInOptional);
buf_index = 0;
return buf_index; 
}

int call_SetEditCurPos() {
int buf_index = 4;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool moveview = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool seekplay = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetEditCurPos(time, moveview, seekplay);
buf_index = 0;
return buf_index; 
}

int call_SetEditCurPos2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool moveview = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool seekplay = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetEditCurPos2(proj, time, moveview, seekplay);
buf_index = 0;
return buf_index; 
}

int call_SetEnvelopeStateChunk() {
int buf_index = 4;
TrackEnvelope* env; memcpy(&env, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(str);
bool isundoOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = SetEnvelopeStateChunk(env, str, isundoOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetExtState() {
int buf_index = 4;
const char* section = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(section);
const char* key = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(key);
const char* value = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(value);
bool persist = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetExtState(section, key, value, persist);
buf_index = 0;
return buf_index; 
}

int call_SetGlobalAutomationOverride() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
SetGlobalAutomationOverride(mode);
buf_index = 0;
return buf_index; 
}

int call_SetItemStateChunk() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(str);
bool isundoOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = SetItemStateChunk(item, str, isundoOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMasterTrackVisibility() {
int buf_index = 4;
int flag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = SetMasterTrackVisibility(flag);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_SetMediaItemInfo_Value() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double newvalue = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = SetMediaItemInfo_Value(item, parmname, newvalue);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMediaItemLength() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
double length = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool refreshUI = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = SetMediaItemLength(item, length, refreshUI);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMediaItemPosition() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
double position = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool refreshUI = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = SetMediaItemPosition(item, position, refreshUI);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMediaItemSelected() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetMediaItemSelected(item, selected);
buf_index = 0;
return buf_index; 
}

int call_SetMediaItemTake_Source() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
PCM_source* source; memcpy(&source, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = SetMediaItemTake_Source(take, source);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMediaItemTakeInfo_Value() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double newvalue = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = SetMediaItemTakeInfo_Value(take, parmname, newvalue);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMediaTrackInfo_Value() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double newvalue = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = SetMediaTrackInfo_Value(tr, parmname, newvalue);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetMIDIEditorGrid() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
double division = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
SetMIDIEditorGrid(project, division);
buf_index = 0;
return buf_index; 
}

int call_SetMixerScroll() {
int buf_index = 4;
MediaTrack* leftmosttrack; memcpy(&leftmosttrack, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* retval = SetMixerScroll(leftmosttrack);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_SetMouseModifier() {
int buf_index = 4;
const char* context = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(context);
int modifier_flag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* action = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(action);
SetMouseModifier(context, modifier_flag, action);
buf_index = 0;
return buf_index; 
}

int call_SetOnlyTrackSelected() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
SetOnlyTrackSelected(track);
buf_index = 0;
return buf_index; 
}

int call_SetProjectGrid() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
double division = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
SetProjectGrid(project, division);
buf_index = 0;
return buf_index; 
}

int call_SetProjectMarker() {
int buf_index = 4;
int markrgnindexnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
bool retval = SetProjectMarker(markrgnindexnumber, isrgn, pos, rgnend, name);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetProjectMarker2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnindexnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
bool retval = SetProjectMarker2(proj, markrgnindexnumber, isrgn, pos, rgnend, name);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetProjectMarker3() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnindexnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int color = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetProjectMarker3(proj, markrgnindexnumber, isrgn, pos, rgnend, name, color);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetProjectMarker4() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnindexnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int color = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int flags = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetProjectMarker4(proj, markrgnindexnumber, isrgn, pos, rgnend, name, color, flags);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetProjectMarkerByIndex() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int IDnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int color = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetProjectMarkerByIndex(proj, markrgnidx, isrgn, pos, rgnend, IDnumber, name, color);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetProjectMarkerByIndex2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int markrgnidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool isrgn = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double rgnend = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int IDnumber = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
int color = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int flags = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetProjectMarkerByIndex2(proj, markrgnidx, isrgn, pos, rgnend, IDnumber, name, color, flags);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetProjExtState() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* extname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(extname);
const char* key = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(key);
const char* value = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(value);
int retval = SetProjExtState(proj, extname, key, value);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_SetRegionRenderMatrix() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int regionindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int addorremove = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
SetRegionRenderMatrix(proj, regionindex, track, addorremove);
buf_index = 0;
return buf_index; 
}

int call_SetTakeStretchMarkerSlope() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double slope = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = SetTakeStretchMarkerSlope(take, idx, slope);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTempoTimeSigMarker() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int ptidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double timepos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int measurepos = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double beatpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double bpm = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int timesig_num = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int timesig_denom = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool lineartempo = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = SetTempoTimeSigMarker(proj, ptidx, timepos, measurepos, beatpos, bpm, timesig_num, timesig_denom, lineartempo);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetToggleCommandState() {
int buf_index = 4;
int section_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int command_id = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int state = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetToggleCommandState(section_id, command_id, state);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackAutomationMode() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
SetTrackAutomationMode(tr, mode);
buf_index = 0;
return buf_index; 
}

int call_SetTrackColor() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int color = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
SetTrackColor(track, color);
buf_index = 0;
return buf_index; 
}

int call_SetTrackMIDILyrics() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int flag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(str);
bool retval = SetTrackMIDILyrics(track, flag, str);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackMIDINoteName() {
int buf_index = 4;
int track = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int pitch = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int chan = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
bool retval = SetTrackMIDINoteName(track, pitch, chan, name);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackMIDINoteNameEx() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int pitch = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int chan = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
bool retval = SetTrackMIDINoteNameEx(proj, track, pitch, chan, name);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackSelected() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool selected = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
SetTrackSelected(track, selected);
buf_index = 0;
return buf_index; 
}

int call_SetTrackSendInfo_Value() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int category = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int sendidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
double newvalue = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = SetTrackSendInfo_Value(tr, category, sendidx, parmname, newvalue);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackSendUIPan() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double pan = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int isend = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetTrackSendUIPan(track, send_idx, pan, isend);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackSendUIVol() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double vol = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int isend = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = SetTrackSendUIVol(track, send_idx, vol, isend);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_SetTrackStateChunk() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* str = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(str);
bool isundoOptional = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = SetTrackStateChunk(track, str, isundoOptional);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_ShowConsoleMsg() {
int buf_index = 4;
const char* msg = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(msg);
ShowConsoleMsg(msg);
buf_index = 0;
return buf_index; 
}

int call_ShowMessageBox() {
int buf_index = 4;
const char* msg = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(msg);
const char* title = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(title);
int type = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = ShowMessageBox(msg, title, type);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_SLIDER2DB() {
int buf_index = 4;
double y = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = SLIDER2DB(y);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_SnapToGrid() {
int buf_index = 4;
ReaProject* project; memcpy(&project, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time_pos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = SnapToGrid(project, time_pos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_SoloAllTracks() {
int buf_index = 4;
int solo = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
SoloAllTracks(solo);
buf_index = 0;
return buf_index; 
}

int call_Splash_GetWnd() {
int buf_index = 4;
HWND retval = Splash_GetWnd();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_SplitMediaItem() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
double position = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
MediaItem* retval = SplitMediaItem(item, position);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_StuffMIDIMessage() {
int buf_index = 4;
int mode = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int msg1 = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int msg2 = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int msg3 = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
StuffMIDIMessage(mode, msg1, msg2, msg3);
buf_index = 0;
return buf_index; 
}

int call_TakeFX_AddByName() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* fxname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fxname);
int instantiate = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = TakeFX_AddByName(take, fxname, instantiate);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_EndParamEdit() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_EndParamEdit(take, fx, param);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_FormatParamValue() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TakeFX_FormatParamValue(take, fx, param, val, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_FormatParamValueNormalized() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double value = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TakeFX_FormatParamValueNormalized(take, fx, param, value, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_GetChainVisible() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TakeFX_GetChainVisible(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_GetCount() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TakeFX_GetCount(take);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_GetEnabled() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_GetEnabled(take, fx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_GetEnvelope() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fxindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int parameterindex = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool create = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TrackEnvelope* retval = TakeFX_GetEnvelope(take, fxindex, parameterindex, create);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TakeFX_GetFloatingWindow() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
HWND retval = TakeFX_GetFloatingWindow(take, index);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TakeFX_GetFormattedParamValue() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_GetFormattedParamValue(take, fx, param, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_GetFXName() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_GetFXName(take, fx, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_GetIOSize() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int inputPinsOutOptional;
int outputPinsOutOptional;
int retval = TakeFX_GetIOSize(take, fx, &inputPinsOutOptional, &outputPinsOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &inputPinsOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &outputPinsOutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_GetNamedConfigParm() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
bool retval = TakeFX_GetNamedConfigParm(take, fx, parmname, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_GetNumParams() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = TakeFX_GetNumParams(take, fx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_GetOpen() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_GetOpen(take, fx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_GetParam() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double minvalOut;
double maxvalOut;
double retval = TakeFX_GetParam(take, fx, param, &minvalOut, &maxvalOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &minvalOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &maxvalOut, 8); buf_index += 8;
return buf_index; 
}

int call_TakeFX_GetParameterStepSizes() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double stepOut;
double smallstepOut;
double largestepOut;
bool istoggleOut;
bool retval = TakeFX_GetParameterStepSizes(take, fx, param, &stepOut, &smallstepOut, &largestepOut, &istoggleOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &stepOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &smallstepOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &largestepOut, 8); buf_index += 8;
sendrecvbuf[buf_index] = istoggleOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_GetParamEx() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double minvalOut;
double maxvalOut;
double midvalOut;
double retval = TakeFX_GetParamEx(take, fx, param, &minvalOut, &maxvalOut, &midvalOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &minvalOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &maxvalOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &midvalOut, 8); buf_index += 8;
return buf_index; 
}

int call_TakeFX_GetParamName() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_GetParamName(take, fx, param, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_GetParamNormalized() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double retval = TakeFX_GetParamNormalized(take, fx, param);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TakeFX_GetPinMappings() {
int buf_index = 4;
MediaItem_Take* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int isOutput = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int pin = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int high32OutOptional;
int retval = TakeFX_GetPinMappings(tr, fx, isOutput, pin, &high32OutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &high32OutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_GetPreset() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_GetPreset(take, fx, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_GetPresetIndex() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int numberOfPresetsOut;
int retval = TakeFX_GetPresetIndex(take, fx, &numberOfPresetsOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &numberOfPresetsOut, 4); buf_index += 4;
return buf_index; 
}

int call_TakeFX_GetUserPresetFilename() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TakeFX_GetUserPresetFilename(take, fx, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TakeFX_NavigatePresets() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int presetmove = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_NavigatePresets(take, fx, presetmove);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_SetEnabled() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool enabled = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TakeFX_SetEnabled(take, fx, enabled);
buf_index = 0;
return buf_index; 
}

int call_TakeFX_SetNamedConfigParm() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
const char* value = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(value);
bool retval = TakeFX_SetNamedConfigParm(take, fx, parmname, value);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_SetOpen() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool open = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TakeFX_SetOpen(take, fx, open);
buf_index = 0;
return buf_index; 
}

int call_TakeFX_SetParam() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TakeFX_SetParam(take, fx, param, val);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_SetParamNormalized() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double value = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TakeFX_SetParamNormalized(take, fx, param, value);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_SetPinMappings() {
int buf_index = 4;
MediaItem_Take* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int isOutput = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int pin = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int low32bits = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int hi32bits = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_SetPinMappings(tr, fx, isOutput, pin, low32bits, hi32bits);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_SetPreset() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* presetname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(presetname);
bool retval = TakeFX_SetPreset(take, fx, presetname);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_SetPresetByIndex() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TakeFX_SetPresetByIndex(take, fx, idx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TakeFX_Show() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
int index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int showFlag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TakeFX_Show(take, index, showFlag);
buf_index = 0;
return buf_index; 
}

int call_TakeIsMIDI() {
int buf_index = 4;
MediaItem_Take* take; memcpy(&take, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool retval = TakeIsMIDI(take);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_time_precise() {
int buf_index = 4;
double retval = time_precise();
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap2_GetDividedBpmAtTime() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap2_GetDividedBpmAtTime(proj, time);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap2_GetNextChangeTime() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap2_GetNextChangeTime(proj, time);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap2_QNToTime() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double qn = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap2_QNToTime(proj, qn);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap2_timeToBeats() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int measuresOutOptional;
int cmlOutOptional;
double fullbeatsOutOptional;
int cdenomOutOptional;
double retval = TimeMap2_timeToBeats(proj, tpos, &measuresOutOptional, &cmlOutOptional, &fullbeatsOutOptional, &cdenomOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &measuresOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &cmlOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &fullbeatsOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &cdenomOutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_TimeMap2_timeToQN() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap2_timeToQN(proj, tpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_curFrameRate() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool dropFrameOutOptional;
double retval = TimeMap_curFrameRate(proj, &dropFrameOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
sendrecvbuf[buf_index] = dropFrameOutOptional ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TimeMap_GetDividedBpmAtTime() {
int buf_index = 4;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap_GetDividedBpmAtTime(time);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_GetMeasureInfo() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int measure = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double qn_startOut;
double qn_endOut;
int timesig_numOut;
int timesig_denomOut;
double tempoOut;
double retval = TimeMap_GetMeasureInfo(proj, measure, &qn_startOut, &qn_endOut, &timesig_numOut, &timesig_denomOut, &tempoOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &qn_startOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &qn_endOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &timesig_numOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &timesig_denomOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &tempoOut, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_GetMetronomePattern() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int retval = TimeMap_GetMetronomePattern(proj, time, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TimeMap_GetTimeSigAtTime() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double time = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
int timesig_numOut;
int timesig_denomOut;
double tempoOut;
TimeMap_GetTimeSigAtTime(proj, time, &timesig_numOut, &timesig_denomOut, &tempoOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &timesig_numOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &timesig_denomOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &tempoOut, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_QNToMeasures() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double qn = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double qnMeasureStartOutOptional;
double qnMeasureEndOutOptional;
int retval = TimeMap_QNToMeasures(proj, qn, &qnMeasureStartOutOptional, &qnMeasureEndOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &qnMeasureStartOutOptional, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &qnMeasureEndOutOptional, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_QNToTime() {
int buf_index = 4;
double qn = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap_QNToTime(qn);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_QNToTime_abs() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double qn = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap_QNToTime_abs(proj, qn);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_timeToQN() {
int buf_index = 4;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap_timeToQN(tpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TimeMap_timeToQN_abs() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
double tpos = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
double retval = TimeMap_timeToQN_abs(proj, tpos);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_ToggleTrackSendUIMute() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int send_idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = ToggleTrackSendUIMute(track, send_idx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_Track_GetPeakHoldDB() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int channel = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool clear = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
double retval = Track_GetPeakHoldDB(track, channel, clear);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_Track_GetPeakInfo() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int channel = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double retval = Track_GetPeakInfo(track, channel);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TrackCtl_SetToolTip() {
int buf_index = 4;
const char* fmt = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fmt);
int xpos = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int ypos = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool topmost = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TrackCtl_SetToolTip(fmt, xpos, ypos, topmost);
buf_index = 0;
return buf_index; 
}

int call_TrackFX_AddByName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* fxname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fxname);
bool recFX = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int instantiate = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = TrackFX_AddByName(track, fxname, recFX, instantiate);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_EndParamEdit() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_EndParamEdit(track, fx, param);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_FormatParamValue() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TrackFX_FormatParamValue(track, fx, param, val, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_FormatParamValueNormalized() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double value = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TrackFX_FormatParamValueNormalized(track, fx, param, value, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_GetByName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* fxname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(fxname);
bool instantiate = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = TrackFX_GetByName(track, fxname, instantiate);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetChainVisible() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TrackFX_GetChainVisible(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetCount() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TrackFX_GetCount(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetEnabled() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetEnabled(track, fx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_GetEQ() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
bool instantiate = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
int retval = TrackFX_GetEQ(track, instantiate);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetEQBandEnabled() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fxidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandtype = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetEQBandEnabled(track, fxidx, bandtype, bandidx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_GetEQParam() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fxidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int paramidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandtypeOut;
int bandidxOut;
int paramtypeOut;
double normvalOut;
bool retval = TrackFX_GetEQParam(track, fxidx, paramidx, &bandtypeOut, &bandidxOut, &paramtypeOut, &normvalOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &bandtypeOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &bandidxOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &paramtypeOut, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &normvalOut, 8); buf_index += 8;
return buf_index; 
}

int call_TrackFX_GetFloatingWindow() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
HWND retval = TrackFX_GetFloatingWindow(track, index);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TrackFX_GetFormattedParamValue() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetFormattedParamValue(track, fx, param, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_GetFXName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetFXName(track, fx, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_GetInstrument() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TrackFX_GetInstrument(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetIOSize() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int inputPinsOutOptional;
int outputPinsOutOptional;
int retval = TrackFX_GetIOSize(track, fx, &inputPinsOutOptional, &outputPinsOutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &inputPinsOutOptional, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &outputPinsOutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetNamedConfigParm() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
bool retval = TrackFX_GetNamedConfigParm(track, fx, parmname, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_GetNumParams() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int retval = TrackFX_GetNumParams(track, fx);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetOpen() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetOpen(track, fx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_GetParam() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double minvalOut;
double maxvalOut;
double retval = TrackFX_GetParam(track, fx, param, &minvalOut, &maxvalOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &minvalOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &maxvalOut, 8); buf_index += 8;
return buf_index; 
}

int call_TrackFX_GetParameterStepSizes() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double stepOut;
double smallstepOut;
double largestepOut;
bool istoggleOut;
bool retval = TrackFX_GetParameterStepSizes(track, fx, param, &stepOut, &smallstepOut, &largestepOut, &istoggleOut);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], &stepOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &smallstepOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &largestepOut, 8); buf_index += 8;
sendrecvbuf[buf_index] = istoggleOut ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_GetParamEx() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double minvalOut;
double maxvalOut;
double midvalOut;
double retval = TrackFX_GetParamEx(track, fx, param, &minvalOut, &maxvalOut, &midvalOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &minvalOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &maxvalOut, 8); buf_index += 8;
memcpy(&sendrecvbuf[buf_index], &midvalOut, 8); buf_index += 8;
return buf_index; 
}

int call_TrackFX_GetParamName() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetParamName(track, fx, param, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_GetParamNormalized() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double retval = TrackFX_GetParamNormalized(track, fx, param);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 8); buf_index += 8;
return buf_index; 
}

int call_TrackFX_GetPinMappings() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int isOutput = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int pin = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int high32OutOptional;
int retval = TrackFX_GetPinMappings(tr, fx, isOutput, pin, &high32OutOptional);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &high32OutOptional, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetPreset() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_GetPreset(track, fx, charbuf0, 65535);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_GetPresetIndex() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int numberOfPresetsOut;
int retval = TrackFX_GetPresetIndex(track, fx, &numberOfPresetsOut);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
memcpy(&sendrecvbuf[buf_index], &numberOfPresetsOut, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetRecChainVisible() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TrackFX_GetRecChainVisible(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetRecCount() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = TrackFX_GetRecCount(track);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_TrackFX_GetUserPresetFilename() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TrackFX_GetUserPresetFilename(track, fx, charbuf0, 65535);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], charbuf0, 1 + strlen(charbuf0)); buf_index += 1 + strlen(charbuf0);
return buf_index; 
}

int call_TrackFX_NavigatePresets() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int presetmove = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_NavigatePresets(track, fx, presetmove);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetEnabled() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool enabled = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TrackFX_SetEnabled(track, fx, enabled);
buf_index = 0;
return buf_index; 
}

int call_TrackFX_SetEQBandEnabled() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fxidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandtype = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool enable = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = TrackFX_SetEQBandEnabled(track, fxidx, bandtype, bandidx, enable);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetEQParam() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fxidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandtype = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int bandidx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int paramtype = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool isnorm = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
bool retval = TrackFX_SetEQParam(track, fxidx, bandtype, bandidx, paramtype, val, isnorm);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetNamedConfigParm() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* parmname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(parmname);
const char* value = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(value);
bool retval = TrackFX_SetNamedConfigParm(track, fx, parmname, value);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetOpen() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool open = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TrackFX_SetOpen(track, fx, open);
buf_index = 0;
return buf_index; 
}

int call_TrackFX_SetParam() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double val = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TrackFX_SetParam(track, fx, param, val);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetParamNormalized() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int param = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
double value = *(double*)&sendrecvbuf[buf_index]; buf_index += 8;
bool retval = TrackFX_SetParamNormalized(track, fx, param, value);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetPinMappings() {
int buf_index = 4;
MediaTrack* tr; memcpy(&tr, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int isOutput = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int pin = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int low32bits = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int hi32bits = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_SetPinMappings(tr, fx, isOutput, pin, low32bits, hi32bits);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetPreset() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* presetname = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(presetname);
bool retval = TrackFX_SetPreset(track, fx, presetname);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_SetPresetByIndex() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int fx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int idx = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
bool retval = TrackFX_SetPresetByIndex(track, fx, idx);
buf_index = 0;
sendrecvbuf[buf_index] = retval ? 1 : 0; buf_index += 1;
return buf_index; 
}

int call_TrackFX_Show() {
int buf_index = 4;
MediaTrack* track; memcpy(&track, &sendrecvbuf[buf_index], 8); buf_index += 8;
int index = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int showFlag = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
TrackFX_Show(track, index, showFlag);
buf_index = 0;
return buf_index; 
}

int call_TrackList_AdjustWindows() {
int buf_index = 4;
bool isMinor = sendrecvbuf[buf_index] ? true : false; buf_index += 1;
TrackList_AdjustWindows(isMinor);
buf_index = 0;
return buf_index; 
}

int call_TrackList_UpdateAllExternalSurfaces() {
int buf_index = 4;
TrackList_UpdateAllExternalSurfaces();
buf_index = 0;
return buf_index; 
}

int call_Undo_BeginBlock() {
int buf_index = 4;
Undo_BeginBlock();
buf_index = 0;
return buf_index; 
}

int call_Undo_BeginBlock2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
Undo_BeginBlock2(proj);
buf_index = 0;
return buf_index; 
}

int call_Undo_CanRedo2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* retval = Undo_CanRedo2(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_Undo_CanUndo2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* retval = Undo_CanUndo2(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], retval, 1 + strlen(retval)); buf_index += 1 + strlen(retval);
return buf_index; 
}

int call_Undo_DoRedo2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = Undo_DoRedo2(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_Undo_DoUndo2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
int retval = Undo_DoUndo2(proj);
buf_index = 0;
memcpy(&sendrecvbuf[buf_index], &retval, 4); buf_index += 4;
return buf_index; 
}

int call_Undo_EndBlock() {
int buf_index = 4;
const char* descchange = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(descchange);
int extraflags = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Undo_EndBlock(descchange, extraflags);
buf_index = 0;
return buf_index; 
}

int call_Undo_EndBlock2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* descchange = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(descchange);
int extraflags = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Undo_EndBlock2(proj, descchange, extraflags);
buf_index = 0;
return buf_index; 
}

int call_Undo_OnStateChange() {
int buf_index = 4;
const char* descchange = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(descchange);
Undo_OnStateChange(descchange);
buf_index = 0;
return buf_index; 
}

int call_Undo_OnStateChange2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* descchange = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(descchange);
Undo_OnStateChange2(proj, descchange);
buf_index = 0;
return buf_index; 
}

int call_Undo_OnStateChange_Item() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* name = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(name);
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
Undo_OnStateChange_Item(proj, name, item);
buf_index = 0;
return buf_index; 
}

int call_Undo_OnStateChangeEx() {
int buf_index = 4;
const char* descchange = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(descchange);
int whichStates = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int trackparm = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Undo_OnStateChangeEx(descchange, whichStates, trackparm);
buf_index = 0;
return buf_index; 
}

int call_Undo_OnStateChangeEx2() {
int buf_index = 4;
ReaProject* proj; memcpy(&proj, &sendrecvbuf[buf_index], 8); buf_index += 8;
const char* descchange = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(descchange);
int whichStates = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
int trackparm = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
Undo_OnStateChangeEx2(proj, descchange, whichStates, trackparm);
buf_index = 0;
return buf_index; 
}

int call_UpdateArrange() {
int buf_index = 4;
UpdateArrange();
buf_index = 0;
return buf_index; 
}

int call_UpdateItemInProject() {
int buf_index = 4;
MediaItem* item; memcpy(&item, &sendrecvbuf[buf_index], 8); buf_index += 8;
UpdateItemInProject(item);
buf_index = 0;
return buf_index; 
}

int call_UpdateTimeline() {
int buf_index = 4;
UpdateTimeline();
buf_index = 0;
return buf_index; 
}

int call_ViewPrefs() {
int buf_index = 4;
int page = *(int*)&sendrecvbuf[buf_index]; buf_index += 4;
const char* pageByName = &sendrecvbuf[buf_index]; buf_index += 1 + strlen(pageByName);
ViewPrefs(page, pageByName);
buf_index = 0;
return buf_index; 
}

void create_ftable() {
functions[0] = call_AddMediaItemToTrack;
functions[1] = call_AddProjectMarker;
functions[2] = call_AddProjectMarker2;
functions[3] = call_AddRemoveReaScript;
functions[4] = call_AddTakeToMediaItem;
functions[5] = call_AddTempoTimeSigMarker;
functions[6] = call_adjustZoom;
functions[7] = call_AnyTrackSolo;
functions[8] = call_APIExists;
functions[9] = call_APITest;
functions[10] = call_ApplyNudge;
functions[11] = call_Audio_Init;
functions[12] = call_Audio_IsPreBuffer;
functions[13] = call_Audio_IsRunning;
functions[14] = call_Audio_Quit;
functions[15] = call_AudioAccessorValidateState;
functions[16] = call_BypassFxAllTracks;
functions[17] = call_ClearAllRecArmed;
functions[18] = call_ClearConsole;
functions[19] = call_ClearPeakCache;
functions[20] = call_ColorFromNative;
functions[21] = call_ColorToNative;
functions[22] = call_CountEnvelopePoints;
functions[23] = call_CountMediaItems;
functions[24] = call_CountProjectMarkers;
functions[25] = call_CountSelectedMediaItems;
functions[26] = call_CountSelectedTracks;
functions[27] = call_CountSelectedTracks2;
functions[28] = call_CountTakeEnvelopes;
functions[29] = call_CountTakes;
functions[30] = call_CountTCPFXParms;
functions[31] = call_CountTempoTimeSigMarkers;
functions[32] = call_CountTrackEnvelopes;
functions[33] = call_CountTrackMediaItems;
functions[34] = call_CountTracks;
functions[36] = call_CreateTakeAudioAccessor;
functions[37] = call_CreateTrackAudioAccessor;
functions[38] = call_CreateTrackSend;
functions[39] = call_CSurf_FlushUndo;
functions[40] = call_CSurf_GetTouchState;
functions[41] = call_CSurf_GoEnd;
functions[42] = call_CSurf_GoStart;
functions[43] = call_CSurf_NumTracks;
functions[44] = call_CSurf_OnArrow;
functions[45] = call_CSurf_OnFwd;
functions[46] = call_CSurf_OnFXChange;
functions[47] = call_CSurf_OnInputMonitorChange;
functions[48] = call_CSurf_OnInputMonitorChangeEx;
functions[49] = call_CSurf_OnMuteChange;
functions[50] = call_CSurf_OnMuteChangeEx;
functions[51] = call_CSurf_OnPanChange;
functions[52] = call_CSurf_OnPanChangeEx;
functions[53] = call_CSurf_OnPause;
functions[54] = call_CSurf_OnPlay;
functions[55] = call_CSurf_OnPlayRateChange;
functions[56] = call_CSurf_OnRecArmChange;
functions[57] = call_CSurf_OnRecArmChangeEx;
functions[58] = call_CSurf_OnRecord;
functions[59] = call_CSurf_OnRecvPanChange;
functions[60] = call_CSurf_OnRecvVolumeChange;
functions[61] = call_CSurf_OnRew;
functions[62] = call_CSurf_OnRewFwd;
functions[63] = call_CSurf_OnScroll;
functions[64] = call_CSurf_OnSelectedChange;
functions[65] = call_CSurf_OnSendPanChange;
functions[66] = call_CSurf_OnSendVolumeChange;
functions[67] = call_CSurf_OnSoloChange;
functions[68] = call_CSurf_OnSoloChangeEx;
functions[69] = call_CSurf_OnStop;
functions[70] = call_CSurf_OnTempoChange;
functions[71] = call_CSurf_OnTrackSelection;
functions[72] = call_CSurf_OnVolumeChange;
functions[73] = call_CSurf_OnVolumeChangeEx;
functions[74] = call_CSurf_OnWidthChange;
functions[75] = call_CSurf_OnWidthChangeEx;
functions[76] = call_CSurf_OnZoom;
functions[77] = call_CSurf_ResetAllCachedVolPanStates;
functions[78] = call_CSurf_ScrubAmt;
functions[79] = call_CSurf_SetAutoMode;
functions[80] = call_CSurf_SetPlayState;
functions[81] = call_CSurf_SetRepeatState;
functions[82] = call_CSurf_SetSurfaceMute;
functions[83] = call_CSurf_SetSurfacePan;
functions[84] = call_CSurf_SetSurfaceRecArm;
functions[85] = call_CSurf_SetSurfaceSelected;
functions[86] = call_CSurf_SetSurfaceSolo;
functions[87] = call_CSurf_SetSurfaceVolume;
functions[88] = call_CSurf_SetTrackListChange;
functions[89] = call_CSurf_TrackFromID;
functions[90] = call_CSurf_TrackToID;
functions[91] = call_DB2SLIDER;
functions[92] = call_DeleteEnvelopePointRange;
functions[93] = call_DeleteExtState;
functions[94] = call_DeleteProjectMarker;
functions[95] = call_DeleteProjectMarkerByIndex;
functions[97] = call_DeleteTempoTimeSigMarker;
functions[98] = call_DeleteTrack;
functions[99] = call_DeleteTrackMediaItem;
functions[100] = call_DestroyAudioAccessor;
functions[101] = call_Dock_UpdateDockID;
functions[102] = call_DockIsChildOfDock;
functions[103] = call_DockWindowActivate;
functions[104] = call_DockWindowAdd;
functions[105] = call_DockWindowAddEx;
functions[106] = call_DockWindowRefresh;
functions[107] = call_DockWindowRefreshForHWND;
functions[108] = call_DockWindowRemove;
functions[109] = call_EditTempoTimeSigMarker;
functions[111] = call_EnumerateFiles;
functions[112] = call_EnumerateSubdirectories;
functions[114] = call_EnumPitchShiftSubModes;
functions[118] = call_EnumProjects;
functions[119] = call_EnumProjExtState;
functions[120] = call_EnumRegionRenderMatrix;
functions[121] = call_EnumTrackMIDIProgramNames;
functions[122] = call_EnumTrackMIDIProgramNamesEx;
functions[123] = call_Envelope_Evaluate;
functions[124] = call_Envelope_FormatValue;
functions[125] = call_Envelope_GetParentTake;
functions[126] = call_Envelope_GetParentTrack;
functions[127] = call_Envelope_SortPoints;
functions[128] = call_ExecProcess;
functions[129] = call_file_exists;
functions[130] = call_FindTempoTimeSigMarker;
functions[131] = call_format_timestr;
functions[132] = call_format_timestr_len;
functions[133] = call_format_timestr_pos;
functions[135] = call_get_ini_file;
functions[136] = call_GetActiveTake;
functions[137] = call_GetAllProjectPlayStates;
functions[138] = call_GetAppVersion;
functions[139] = call_GetAudioAccessorEndTime;
functions[140] = call_GetAudioAccessorHash;
functions[142] = call_GetAudioAccessorStartTime;
functions[143] = call_GetConfigWantsDock;
functions[144] = call_GetCurrentProjectInLoadSave;
functions[145] = call_GetCursorContext;
functions[146] = call_GetCursorContext2;
functions[147] = call_GetCursorPosition;
functions[148] = call_GetCursorPositionEx;
functions[149] = call_GetDisplayedMediaItemColor;
functions[150] = call_GetDisplayedMediaItemColor2;
functions[151] = call_GetEnvelopeName;
functions[152] = call_GetEnvelopePoint;
functions[153] = call_GetEnvelopePointByTime;
functions[154] = call_GetEnvelopeScalingMode;
functions[155] = call_GetEnvelopeStateChunk;
functions[156] = call_GetExePath;
functions[157] = call_GetExtState;
functions[158] = call_GetFocusedFX;
functions[159] = call_GetFreeDiskSpaceForRecordPath;
functions[160] = call_GetFXEnvelope;
functions[161] = call_GetGlobalAutomationOverride;
functions[162] = call_GetHZoomLevel;
functions[163] = call_GetInputChannelName;
functions[164] = call_GetInputOutputLatency;
functions[166] = call_GetItemProjectContext;
functions[167] = call_GetItemStateChunk;
functions[168] = call_GetLastColorThemeFile;
functions[169] = call_GetLastMarkerAndCurRegion;
functions[170] = call_GetLastTouchedFX;
functions[171] = call_GetLastTouchedTrack;
functions[172] = call_GetMainHwnd;
functions[173] = call_GetMasterMuteSoloFlags;
functions[174] = call_GetMasterTrack;
functions[175] = call_GetMasterTrackVisibility;
functions[176] = call_GetMaxMidiInputs;
functions[177] = call_GetMaxMidiOutputs;
functions[178] = call_GetMediaItem;
functions[179] = call_GetMediaItem_Track;
functions[180] = call_GetMediaItemInfo_Value;
functions[181] = call_GetMediaItemNumTakes;
functions[182] = call_GetMediaItemTake;
functions[183] = call_GetMediaItemTake_Item;
functions[185] = call_GetMediaItemTake_Source;
functions[186] = call_GetMediaItemTake_Track;
functions[188] = call_GetMediaItemTakeInfo_Value;
functions[189] = call_GetMediaItemTrack;
functions[190] = call_GetMediaSourceFileName;
functions[191] = call_GetMediaSourceLength;
functions[192] = call_GetMediaSourceNumChannels;
functions[193] = call_GetMediaSourceParent;
functions[194] = call_GetMediaSourceSampleRate;
functions[195] = call_GetMediaSourceType;
functions[196] = call_GetMediaTrackInfo_Value;
functions[197] = call_GetMIDIInputName;
functions[198] = call_GetMIDIOutputName;
functions[199] = call_GetMixerScroll;
functions[200] = call_GetMouseModifier;
functions[201] = call_GetMousePosition;
functions[202] = call_GetNumAudioInputs;
functions[203] = call_GetNumAudioOutputs;
functions[204] = call_GetNumMIDIInputs;
functions[205] = call_GetNumMIDIOutputs;
functions[206] = call_GetNumTracks;
functions[207] = call_GetOS;
functions[208] = call_GetOutputChannelName;
functions[209] = call_GetOutputLatency;
functions[210] = call_GetParentTrack;
functions[211] = call_GetPeakFileName;
functions[212] = call_GetPeakFileNameEx;
functions[213] = call_GetPeakFileNameEx2;
functions[214] = call_GetPlayPosition;
functions[215] = call_GetPlayPosition2;
functions[216] = call_GetPlayPosition2Ex;
functions[217] = call_GetPlayPositionEx;
functions[218] = call_GetPlayState;
functions[219] = call_GetPlayStateEx;
functions[220] = call_GetProjectLength;
functions[221] = call_GetProjectName;
functions[222] = call_GetProjectPath;
functions[223] = call_GetProjectPathEx;
functions[224] = call_GetProjectStateChangeCount;
functions[225] = call_GetProjectTimeOffset;
functions[226] = call_GetProjectTimeSignature;
functions[227] = call_GetProjectTimeSignature2;
functions[228] = call_GetProjExtState;
functions[229] = call_GetResourcePath;
functions[230] = call_GetSelectedEnvelope;
functions[231] = call_GetSelectedMediaItem;
functions[232] = call_GetSelectedTrack;
functions[233] = call_GetSelectedTrack2;
functions[234] = call_GetSelectedTrackEnvelope;
functions[235] = call_GetSet_ArrangeView2;
functions[236] = call_GetSet_LoopTimeRange;
functions[237] = call_GetSet_LoopTimeRange2;
functions[238] = call_GetSetEnvelopeState;
functions[239] = call_GetSetEnvelopeState2;
functions[240] = call_GetSetItemState;
functions[241] = call_GetSetItemState2;
functions[242] = call_GetSetMediaItemTakeInfo_String;
functions[243] = call_GetSetMediaTrackInfo_String;
functions[244] = call_GetSetProjectAuthor;
functions[246] = call_GetSetProjectNotes;
functions[247] = call_GetSetRepeat;
functions[248] = call_GetSetRepeatEx;
functions[250] = call_GetSetTrackState;
functions[251] = call_GetSetTrackState2;
functions[252] = call_GetSubProjectFromSource;
functions[253] = call_GetTake;
functions[254] = call_GetTakeEnvelope;
functions[255] = call_GetTakeEnvelopeByName;
functions[256] = call_GetTakeName;
functions[257] = call_GetTakeNumStretchMarkers;
functions[258] = call_GetTakeStretchMarker;
functions[259] = call_GetTakeStretchMarkerSlope;
functions[260] = call_GetTCPFXParm;
functions[261] = call_GetTempoMatchPlayRate;
functions[262] = call_GetTempoTimeSigMarker;
functions[263] = call_GetToggleCommandState;
functions[264] = call_GetToggleCommandStateEx;
functions[265] = call_GetTooltipWindow;
functions[266] = call_GetTrack;
functions[267] = call_GetTrackAutomationMode;
functions[268] = call_GetTrackColor;
functions[269] = call_GetTrackDepth;
functions[270] = call_GetTrackEnvelope;
functions[271] = call_GetTrackEnvelopeByChunkName;
functions[272] = call_GetTrackEnvelopeByName;
functions[274] = call_GetTrackMediaItem;
functions[276] = call_GetTrackMIDINoteName;
functions[277] = call_GetTrackMIDINoteNameEx;
functions[278] = call_GetTrackMIDINoteRange;
functions[279] = call_GetTrackName;
functions[280] = call_GetTrackNumMediaItems;
functions[281] = call_GetTrackNumSends;
functions[282] = call_GetTrackReceiveName;
functions[283] = call_GetTrackReceiveUIMute;
functions[284] = call_GetTrackReceiveUIVolPan;
functions[285] = call_GetTrackSendInfo_Value;
functions[286] = call_GetTrackSendName;
functions[287] = call_GetTrackSendUIMute;
functions[288] = call_GetTrackSendUIVolPan;
functions[289] = call_GetTrackState;
functions[290] = call_GetTrackStateChunk;
functions[291] = call_GetTrackUIMute;
functions[292] = call_GetTrackUIPan;
functions[293] = call_GetTrackUIVolPan;
functions[294] = call_GetUserFileNameForRead;
functions[295] = call_GetUserInputs;
functions[296] = call_GoToMarker;
functions[297] = call_GoToRegion;
functions[298] = call_GR_SelectColor;
functions[299] = call_GSC_mainwnd;
functions[301] = call_HasExtState;
functions[302] = call_HasTrackMIDIPrograms;
functions[303] = call_HasTrackMIDIProgramsEx;
functions[304] = call_Help_Set;
functions[305] = call_image_resolve_fn;
functions[307] = call_InsertMedia;
functions[308] = call_InsertMediaSection;
functions[309] = call_InsertTrackAtIndex;
functions[310] = call_IsMediaExtension;
functions[311] = call_IsMediaItemSelected;
functions[312] = call_IsProjectDirty;
functions[313] = call_IsTrackSelected;
functions[314] = call_IsTrackVisible;
functions[323] = call_LICE_ClipLine;
functions[324] = call_Loop_OnArrow;
functions[325] = call_Main_OnCommand;
functions[326] = call_Main_OnCommandEx;
functions[327] = call_Main_openProject;
functions[328] = call_Main_SaveProject;
functions[329] = call_Main_UpdateLoopInfo;
functions[330] = call_MarkProjectDirty;
functions[331] = call_MarkTrackItemsDirty;
functions[332] = call_Master_GetPlayRate;
functions[333] = call_Master_GetPlayRateAtTime;
functions[334] = call_Master_GetTempo;
functions[335] = call_Master_NormalizePlayRate;
functions[336] = call_Master_NormalizeTempo;
functions[337] = call_MB;
functions[338] = call_MediaItemDescendsFromTrack;
functions[339] = call_MIDI_CountEvts;
functions[340] = call_MIDI_DeleteCC;
functions[341] = call_MIDI_DeleteEvt;
functions[342] = call_MIDI_DeleteNote;
functions[343] = call_MIDI_DeleteTextSysexEvt;
functions[344] = call_MIDI_EnumSelCC;
functions[345] = call_MIDI_EnumSelEvts;
functions[346] = call_MIDI_EnumSelNotes;
functions[347] = call_MIDI_EnumSelTextSysexEvts;
functions[349] = call_MIDI_GetCC;
functions[351] = call_MIDI_GetGrid;
functions[352] = call_MIDI_GetHash;
functions[353] = call_MIDI_GetNote;
functions[354] = call_MIDI_GetPPQPos_EndOfMeasure;
functions[355] = call_MIDI_GetPPQPos_StartOfMeasure;
functions[356] = call_MIDI_GetPPQPosFromProjQN;
functions[357] = call_MIDI_GetPPQPosFromProjTime;
functions[358] = call_MIDI_GetProjQNFromPPQPos;
functions[359] = call_MIDI_GetProjTimeFromPPQPos;
functions[360] = call_MIDI_GetScale;
functions[362] = call_MIDI_GetTrackHash;
functions[363] = call_MIDI_InsertCC;
functions[364] = call_MIDI_InsertEvt;
functions[366] = call_MIDI_InsertTextSysexEvt;
functions[367] = call_midi_reinit;
functions[368] = call_MIDI_SelectAll;
functions[369] = call_MIDI_SetAllEvts;
functions[372] = call_MIDI_SetItemExtents;
functions[375] = call_MIDI_Sort;
functions[376] = call_MIDIEditor_GetActive;
functions[377] = call_MIDIEditor_GetMode;
functions[378] = call_MIDIEditor_GetSetting_int;
functions[379] = call_MIDIEditor_GetSetting_str;
functions[380] = call_MIDIEditor_GetTake;
functions[381] = call_MIDIEditor_LastFocused_OnCommand;
functions[382] = call_MIDIEditor_OnCommand;
functions[383] = call_mkpanstr;
functions[384] = call_mkvolpanstr;
functions[385] = call_mkvolstr;
functions[386] = call_MoveEditCursor;
functions[387] = call_MoveMediaItemToTrack;
functions[388] = call_MuteAllTracks;
functions[390] = call_NamedCommandLookup;
functions[391] = call_OnPauseButton;
functions[392] = call_OnPauseButtonEx;
functions[393] = call_OnPlayButton;
functions[394] = call_OnPlayButtonEx;
functions[395] = call_OnStopButton;
functions[396] = call_OnStopButtonEx;
functions[397] = call_OpenColorThemeFile;
functions[398] = call_OpenMediaExplorer;
functions[400] = call_parse_timestr;
functions[401] = call_parse_timestr_len;
functions[402] = call_parse_timestr_pos;
functions[403] = call_parsepanstr;
functions[405] = call_PCM_Sink_GetExtension;
functions[406] = call_PCM_Sink_ShowConfig;
functions[407] = call_PCM_Source_CreateFromFile;
functions[408] = call_PCM_Source_CreateFromFileEx;
functions[409] = call_PCM_Source_CreateFromType;
functions[410] = call_PCM_Source_Destroy;
functions[412] = call_PCM_Source_GetSectionInfo;
functions[413] = call_PluginWantsAlwaysRunFx;
functions[414] = call_PreventUIRefresh;
functions[415] = call_ReaScriptError;
functions[417] = call_RefreshToolbar;
functions[418] = call_RefreshToolbar2;
functions[419] = call_relative_fn;
functions[420] = call_RemoveTrackSend;
functions[421] = call_RenderFileSection;
functions[422] = call_Resample_EnumModes;
functions[423] = call_resolve_fn;
functions[424] = call_resolve_fn2;
functions[425] = call_ReverseNamedCommandLookup;
functions[426] = call_ScaleFromEnvelopeMode;
functions[427] = call_ScaleToEnvelopeMode;
functions[428] = call_SelectAllMediaItems;
functions[429] = call_SelectProjectInstance;
functions[430] = call_SetActiveTake;
functions[431] = call_SetAutomationMode;
functions[432] = call_SetCurrentBPM;
functions[433] = call_SetCursorContext;
functions[434] = call_SetEditCurPos;
functions[435] = call_SetEditCurPos2;
functions[437] = call_SetEnvelopeStateChunk;
functions[438] = call_SetExtState;
functions[439] = call_SetGlobalAutomationOverride;
functions[440] = call_SetItemStateChunk;
functions[441] = call_SetMasterTrackVisibility;
functions[442] = call_SetMediaItemInfo_Value;
functions[443] = call_SetMediaItemLength;
functions[444] = call_SetMediaItemPosition;
functions[445] = call_SetMediaItemSelected;
functions[446] = call_SetMediaItemTake_Source;
functions[447] = call_SetMediaItemTakeInfo_Value;
functions[448] = call_SetMediaTrackInfo_Value;
functions[449] = call_SetMIDIEditorGrid;
functions[450] = call_SetMixerScroll;
functions[451] = call_SetMouseModifier;
functions[452] = call_SetOnlyTrackSelected;
functions[453] = call_SetProjectGrid;
functions[454] = call_SetProjectMarker;
functions[455] = call_SetProjectMarker2;
functions[456] = call_SetProjectMarker3;
functions[457] = call_SetProjectMarker4;
functions[458] = call_SetProjectMarkerByIndex;
functions[459] = call_SetProjectMarkerByIndex2;
functions[460] = call_SetProjExtState;
functions[461] = call_SetRegionRenderMatrix;
functions[463] = call_SetTakeStretchMarkerSlope;
functions[464] = call_SetTempoTimeSigMarker;
functions[465] = call_SetToggleCommandState;
functions[466] = call_SetTrackAutomationMode;
functions[467] = call_SetTrackColor;
functions[468] = call_SetTrackMIDILyrics;
functions[469] = call_SetTrackMIDINoteName;
functions[470] = call_SetTrackMIDINoteNameEx;
functions[471] = call_SetTrackSelected;
functions[472] = call_SetTrackSendInfo_Value;
functions[473] = call_SetTrackSendUIPan;
functions[474] = call_SetTrackSendUIVol;
functions[475] = call_SetTrackStateChunk;
functions[477] = call_ShowConsoleMsg;
functions[478] = call_ShowMessageBox;
functions[479] = call_SLIDER2DB;
functions[480] = call_SnapToGrid;
functions[481] = call_SoloAllTracks;
functions[482] = call_Splash_GetWnd;
functions[483] = call_SplitMediaItem;
functions[485] = call_StuffMIDIMessage;
functions[486] = call_TakeFX_AddByName;
functions[487] = call_TakeFX_EndParamEdit;
functions[488] = call_TakeFX_FormatParamValue;
functions[489] = call_TakeFX_FormatParamValueNormalized;
functions[490] = call_TakeFX_GetChainVisible;
functions[491] = call_TakeFX_GetCount;
functions[492] = call_TakeFX_GetEnabled;
functions[493] = call_TakeFX_GetEnvelope;
functions[494] = call_TakeFX_GetFloatingWindow;
functions[495] = call_TakeFX_GetFormattedParamValue;
functions[497] = call_TakeFX_GetFXName;
functions[498] = call_TakeFX_GetIOSize;
functions[499] = call_TakeFX_GetNamedConfigParm;
functions[500] = call_TakeFX_GetNumParams;
functions[501] = call_TakeFX_GetOpen;
functions[502] = call_TakeFX_GetParam;
functions[503] = call_TakeFX_GetParameterStepSizes;
functions[504] = call_TakeFX_GetParamEx;
functions[505] = call_TakeFX_GetParamName;
functions[506] = call_TakeFX_GetParamNormalized;
functions[507] = call_TakeFX_GetPinMappings;
functions[508] = call_TakeFX_GetPreset;
functions[509] = call_TakeFX_GetPresetIndex;
functions[510] = call_TakeFX_GetUserPresetFilename;
functions[511] = call_TakeFX_NavigatePresets;
functions[512] = call_TakeFX_SetEnabled;
functions[513] = call_TakeFX_SetNamedConfigParm;
functions[514] = call_TakeFX_SetOpen;
functions[515] = call_TakeFX_SetParam;
functions[516] = call_TakeFX_SetParamNormalized;
functions[517] = call_TakeFX_SetPinMappings;
functions[518] = call_TakeFX_SetPreset;
functions[519] = call_TakeFX_SetPresetByIndex;
functions[520] = call_TakeFX_Show;
functions[521] = call_TakeIsMIDI;
functions[522] = call_time_precise;
functions[524] = call_TimeMap2_GetDividedBpmAtTime;
functions[525] = call_TimeMap2_GetNextChangeTime;
functions[526] = call_TimeMap2_QNToTime;
functions[527] = call_TimeMap2_timeToBeats;
functions[528] = call_TimeMap2_timeToQN;
functions[529] = call_TimeMap_curFrameRate;
functions[530] = call_TimeMap_GetDividedBpmAtTime;
functions[531] = call_TimeMap_GetMeasureInfo;
functions[532] = call_TimeMap_GetMetronomePattern;
functions[533] = call_TimeMap_GetTimeSigAtTime;
functions[534] = call_TimeMap_QNToMeasures;
functions[535] = call_TimeMap_QNToTime;
functions[536] = call_TimeMap_QNToTime_abs;
functions[537] = call_TimeMap_timeToQN;
functions[538] = call_TimeMap_timeToQN_abs;
functions[539] = call_ToggleTrackSendUIMute;
functions[540] = call_Track_GetPeakHoldDB;
functions[541] = call_Track_GetPeakInfo;
functions[542] = call_TrackCtl_SetToolTip;
functions[543] = call_TrackFX_AddByName;
functions[544] = call_TrackFX_EndParamEdit;
functions[545] = call_TrackFX_FormatParamValue;
functions[546] = call_TrackFX_FormatParamValueNormalized;
functions[547] = call_TrackFX_GetByName;
functions[548] = call_TrackFX_GetChainVisible;
functions[549] = call_TrackFX_GetCount;
functions[550] = call_TrackFX_GetEnabled;
functions[551] = call_TrackFX_GetEQ;
functions[552] = call_TrackFX_GetEQBandEnabled;
functions[553] = call_TrackFX_GetEQParam;
functions[554] = call_TrackFX_GetFloatingWindow;
functions[555] = call_TrackFX_GetFormattedParamValue;
functions[557] = call_TrackFX_GetFXName;
functions[558] = call_TrackFX_GetInstrument;
functions[559] = call_TrackFX_GetIOSize;
functions[560] = call_TrackFX_GetNamedConfigParm;
functions[561] = call_TrackFX_GetNumParams;
functions[562] = call_TrackFX_GetOpen;
functions[563] = call_TrackFX_GetParam;
functions[564] = call_TrackFX_GetParameterStepSizes;
functions[565] = call_TrackFX_GetParamEx;
functions[566] = call_TrackFX_GetParamName;
functions[567] = call_TrackFX_GetParamNormalized;
functions[568] = call_TrackFX_GetPinMappings;
functions[569] = call_TrackFX_GetPreset;
functions[570] = call_TrackFX_GetPresetIndex;
functions[571] = call_TrackFX_GetRecChainVisible;
functions[572] = call_TrackFX_GetRecCount;
functions[573] = call_TrackFX_GetUserPresetFilename;
functions[574] = call_TrackFX_NavigatePresets;
functions[575] = call_TrackFX_SetEnabled;
functions[576] = call_TrackFX_SetEQBandEnabled;
functions[577] = call_TrackFX_SetEQParam;
functions[578] = call_TrackFX_SetNamedConfigParm;
functions[579] = call_TrackFX_SetOpen;
functions[580] = call_TrackFX_SetParam;
functions[581] = call_TrackFX_SetParamNormalized;
functions[582] = call_TrackFX_SetPinMappings;
functions[583] = call_TrackFX_SetPreset;
functions[584] = call_TrackFX_SetPresetByIndex;
functions[585] = call_TrackFX_Show;
functions[586] = call_TrackList_AdjustWindows;
functions[587] = call_TrackList_UpdateAllExternalSurfaces;
functions[588] = call_Undo_BeginBlock;
functions[589] = call_Undo_BeginBlock2;
functions[590] = call_Undo_CanRedo2;
functions[591] = call_Undo_CanUndo2;
functions[592] = call_Undo_DoRedo2;
functions[593] = call_Undo_DoUndo2;
functions[594] = call_Undo_EndBlock;
functions[595] = call_Undo_EndBlock2;
functions[596] = call_Undo_OnStateChange;
functions[597] = call_Undo_OnStateChange2;
functions[598] = call_Undo_OnStateChange_Item;
functions[599] = call_Undo_OnStateChangeEx;
functions[600] = call_Undo_OnStateChangeEx2;
functions[601] = call_UpdateArrange;
functions[602] = call_UpdateItemInProject;
functions[603] = call_UpdateTimeline;
functions[606] = call_ViewPrefs;
}
