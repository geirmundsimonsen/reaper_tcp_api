// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#define REAPERAPI_IMPLEMENT

#include <windows.h>
#include "reaper_plugin.h"
#include "reaper_plugin_functions.h"
#include "reaper_tcp_api.h"
#include "connection.h"
#include <iostream>


REAPER_PLUGIN_HINSTANCE g_hInst;
reaper_plugin_info_t* g_plugin_info;
HWND g_parent;
gaccel_register_t acreg = { { 0, 0, 0 }, "Connect to TCP command server" };
int g_registered_command = 0;



bool hookCommandProc(int command, int flag) {
	if (g_registered_command && command == g_registered_command) {
		connect();
		return true;
	}
	return false;
}



extern "C"
{
	REAPER_PLUGIN_DLL_EXPORT int REAPER_PLUGIN_ENTRYPOINT(REAPER_PLUGIN_HINSTANCE hInstance, reaper_plugin_info_t *rec) {

		if (rec) {
			if (rec->caller_version != REAPER_PLUGIN_VERSION || !rec->GetFunc)
				return 0;

			g_hInst = hInstance;
			g_plugin_info = rec;
			g_parent = rec->hwnd_main;

			REAPERAPI_LoadAPI(rec->GetFunc);

			acreg.accel.cmd = g_registered_command = rec->Register("command_id", (void*)"TCPCOMMAND");
			if (!g_registered_command) return 0;

			rec->Register("gaccel", &acreg);
			rec->Register("hookcommand", (void*)hookCommandProc);

			create_ftable();

			return 1;
		} else {
			return 0;
		}
	}
};