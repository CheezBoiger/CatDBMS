#ifndef _SECURITY_H_
#define _SECURITY_H_

#pragma once

namespace security
{
	enum security_levels
	{
		SECURE_DEFAULT      = 0x000000,
		SECURE_COMMON       = 0xADFFFF,
		SECURE_UNCLASSIFIED = 0xD344DF,
		SECURE_CLASSIFIED   = 0x566DFF,
		SECURE_TOP_SECRET   = 0xFFFFFD,
	};

} /* catdb namespace */


#endif /* _SECURITY_H_ */
