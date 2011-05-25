#include "String.h"

namespace Fitgy { namespace Util {

String intToString(int value) {
	std::stringstream ss;
	ss << value;

	return ss.str();
}

String floatToString(float value) {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << value;

	return ss.str();
}

}}
