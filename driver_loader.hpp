#ifndef DRIVER_LOADER_HPP
#define DRIVER_LOADER_HPP

#pragma comment(lib, "driver_loader.lib")

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

namespace smex_map
{
	enum class driver_load_status : std::uint32_t
	{
		success                   = 0,
		invalid_params            = 1,
		unset_target              = 2,
		unset_vuln                = 3,
		invalid_paths             = 4,
		vuln_failed_start         = 5,
		vuln_failed_end           = 6,
		failed_map                = 7,
		ld_invalid_signature      = 8,
		ld_failed_clean           = 9,
		ld_failed_hook            = 10,
		invalid
	};

	void set_target( std::vector<std::uint8_t>* driver_raw );
	void set_target( std::wstring driver_path );
	void set_vuln( std::wstring driver_path );

	driver_load_status load_driver( std::uint64_t* handler = 0 );
}

#endif