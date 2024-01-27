#include "pch.h"
#include "core_adapter_new.h"

#include <connections/core.h>

namespace nearby::windows {

	Core* InitCore(ServiceControllerRouter* router) {
		return new nearby::connections::Core(router);
	}
}
