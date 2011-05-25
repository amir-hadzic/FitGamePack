/**
*    This file is part of FitGamePack.
*
*    FitGamePack is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    FitGamePack is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with FitGamePack.  If not, see <http://www.gnu.org/licenses/>.
*
*    Author: Amir Hadzic <amir.hadzic@randomshouting.com>
*/

#include "Path.h"

namespace Fitgy { namespace Util {

String executablePath() {
	String path;

#ifdef _WIN32
	TCHAR buffer[255];
	GetModuleFileName(NULL, buffer, 255);
	path = String(buffer);
#else
	char buffer[255];
	int readChars = readlink("/proc/self/exe", buffer, 255);
	buffer[readChars] = '\0';
	path = String(buffer);
#endif

	path = path.substr(0, path.find_last_of('/'));

	return path;
}

}}
