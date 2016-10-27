//
//	Copyright (C) 2015 - 2016 Hong Jen Yee (PCMan) <pcman.tw@gmail.com>
//
//	This library is free software; you can redistribute it and/or
//	modify it under the terms of the GNU Library General Public
//	License as published by the Free Software Foundation; either
//	version 2 of the License, or (at your option) any later version.
//
//	This library is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//	Library General Public License for more details.
//
//	You should have received a copy of the GNU Library General Public
//	License along with this library; if not, write to the
//	Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
//	Boston, MA  02110-1301, USA.
//

#ifndef _BACKEND_SERVER_H_
#define _BACKEND_SERVER_H_

#include <Windows.h>
#include <ShlObj.h>
#include <Shellapi.h>
#include <Lmcons.h> // for UNLEN
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include "../libpipe/libpipe.h"

class BackendServer {
public:
	BackendServer():
		process_(INVALID_HANDLE_VALUE),
		stdin_(INVALID_HANDLE_VALUE),
		stdout_(INVALID_HANDLE_VALUE) {
	}
	~BackendServer();

	void start();
	void terminate();
	bool isRunning();
	bool ping(int timeout=3000);

	string name_;
	string pipeName_;
	wstring command_;
	wstring params_;
	wstring workingDir_;
	HANDLE process_;
	HANDLE stdin_;
	HANDLE stdout_;
};



#endif // _BACKEND_SERVER_H_
